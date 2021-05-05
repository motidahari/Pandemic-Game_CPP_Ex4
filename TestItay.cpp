#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"


using namespace pandemic;
using namespace std;


Player &take_5_blue_cards(Player &player)
{

    return player.take_card(City::Washington)
        .take_card(City::NewYork)
        .take_card(City::Atlanta)
        .take_card(City::Montreal)
        .take_card(City::SanFrancisco);
}

Player &take_some_5_cards(Player &player)
{
    return player.take_card(City::Washington)
        .take_card(City::NewYork)
        .take_card(City::Miami)
        .take_card(City::Mumbai)
        .take_card(City::Istanbul);
}

TEST_CASE("Board initialization"){

    Board b;
    Player player(b, City::Atlanta);

    CHECK(b.is_clean());
    b[City::Atlanta] = -3;
    CHECK(b.is_clean());

    CHECK_THROWS(player.treat(City::Atlanta)); // Atlanta's disease level = 0 => throw
    b[City::Atlanta] = 1;            // Set disease lv.1

    CHECK(!b.is_clean());

    CHECK_NOTHROW(player.treat(City::Atlanta));                // Check if players moves affect the board

    CHECK_THROWS(player.treat(City::Atlanta));    // city disease lv. is 0
    b[City::Atlanta] = 1;
    CHECK_NOTHROW(player.take_card(City::Atlanta)
                        .treat(City::Atlanta));


    CHECK(b.is_clean());

    CHECK(b[City::Atlanta] == 0);

    // Check if the board is correctly connected
    CHECK_NOTHROW(player.drive(City::Chicago)); // Connected to ATL
    CHECK_NOTHROW(player.drive(City::Atlanta));

    CHECK_NOTHROW(player.drive(City::Washington)); // Connected to ATL
    CHECK_NOTHROW(player.drive(City::Atlanta));

    CHECK_NOTHROW(player.drive(City::Miami)); // Connected to ATL
    CHECK_NOTHROW(player.drive(City::Atlanta));

    CHECK_THROWS(player.drive(City::NewYork)); // Not connected to ATL
    CHECK_THROWS(player.drive(City::Bogota));  // Not connected to ATL
    CHECK_THROWS(player.drive(City::Bangkok)); // Not connected to ATL


    // Some connected cities, try to drive between them (possible according to game board)
    CHECK_NOTHROW(player.drive(City::Miami)
                        .drive(City::Bogota)
                        .drive(City::SaoPaulo)
                        .drive(City::Lagos)); 
}

TEST_CASE("treat(City)") {
    Board b;
    Player p{b, City::Atlanta};
    // treat() before cure is discovered:
    CHECK_THROWS(p.treat(City::Atlanta));    // Disease lv. is 0 

    b[City::Atlanta] = 2;

    CHECK_NOTHROW(p.treat(City::Atlanta)
                    .treat(City::Atlanta));               // Disease Lv is 0

    CHECK_THROWS(p.treat(City::Atlanta));                // Checks also that treat() reduces disease cubes

    b[City::Beijing] = 2;
    CHECK_THROWS(p.treat(City::Beijing));   // Not in beijing - fail.
    CHECK_NOTHROW(p.take_card(City::Beijing).take_card(City::Atlanta)
                    .fly_direct(City::Beijing)
                    .treat(City::Beijing)
                    .treat(City::Beijing)
                    .fly_direct(City::Atlanta)); // Go to beijin, treat the disease and come back to ATL

    p.take_card(City::Atlanta)
        .build();
    take_5_blue_cards(p);
    p.discover_cure(Color::Blue);       // Discover a cure to blue disease

    // treat() after cure is discovered:
    CHECK_THROWS(p.treat(City::Atlanta));   // cure discovered, no disease

    b[City::Atlanta] = 1000;
    CHECK_NOTHROW(p.treat(City::Atlanta));           // After cure to blue disease is found - treat sets cube count to 0
    CHECK_THROWS(p.treat(City::Atlanta));

    b[City::Atlanta] = 1000;
    CHECK_THROWS(p.treat(City::HoChiMinhCity)); // Not in correct city.
    CHECK_NOTHROW(p.treat(City::Atlanta));  // Repeat 


    CHECK(b.is_clean());        // Checks that treat cleaned up the disease count.
    
}

TEST_CASE("drive(City) / 3 * fly(City):") { 
    // Dispatcher can fly_direct from a city with research station anywhere without 
    // Discarding a card. In here check that a Player cannot.

    Board b;
    Player p{b, City::Atlanta};

    CHECK_THROWS(p.drive(City::Baghdad)); // Not connected to ATL
    CHECK_THROWS(p.drive(City::Bangkok));      
    CHECK_NOTHROW(p.drive(City::Atlanta)); // drive to current city shouldn't throw *** 


    CHECK_NOTHROW(p.take_card(City::Atlanta)
                   .take_card(City::Atlanta)   
                   .fly_charter(City::SaoPaulo));  // check if take_card() gives a card twice or once - should give once

    CHECK_THROWS(p.fly_direct(City::Atlanta));     // No cards in hand

    CHECK_THROWS(p.fly_direct(City::Bangkok));  // Player does not have dest card
    CHECK_THROWS(p.fly_charter(City::Bangkok)); // Player does not have src card
    CHECK_THROWS(p.fly_shuttle(City::Bangkok)); // No research station in Bangkok nor in Atlanta

    CHECK_NOTHROW(p.take_card(City::Atlanta).fly_direct(City::Atlanta)); // Return to ATL


    CHECK_NOTHROW(p.take_card(City::Atlanta)
                    .fly_direct(City::Atlanta)); // fly to current city with city card in hand. *** 

    CHECK_THROWS(p.fly_direct(City::Atlanta));   // fly to current city with no card in hand
  
    CHECK_NOTHROW(p.take_card(City::Atlanta)
                   .fly_charter(City::Atlanta)); // fly to current city with a city card in hand. ***
    
    CHECK_THROWS(p.fly_charter(City::Atlanta));  // fly_charter to current city without a city card in hand
    
    p.take_card(City::Atlanta)
                    .build();                 // Build a Research station in ATL
    
    CHECK_NOTHROW(p.fly_shuttle(City::Atlanta)); // Shuttle to current city.

    CHECK_NOTHROW(p.take_card(City::Beijing)
                    .fly_direct(City::Beijing)   // Fly to Beijing
                    .take_card(City::Beijing)
                    .build()                     // Build a research station in Beijing
                    .fly_shuttle(City::Atlanta));// Shuttle back


    p.take_card(City::Beijing).take_card(City::Atlanta); // Take Beijing and Atlanta cards
    CHECK_NOTHROW(p.fly_shuttle(City::Beijing)
                    .fly_shuttle(City::Atlanta));       // Check that fly_shuttle() does not use a card

    CHECK_NOTHROW(p.fly_direct(City::Beijing).fly_direct(City::Atlanta)); // Cards remained so can fly.

    CHECK_THROWS(p.fly_direct(City::Beijing));          // No cards remaining.

    p.take_card(City::HoChiMinhCity).fly_direct(City::HoChiMinhCity);

    CHECK_THROWS(p.build());                        // Checks that fly_direct uses a card.

}

TEST_CASE("build() and discover_cure(Color)") {

    Board b;
    Player p{b, City::Atlanta};

    CHECK_THROWS(p.build());
    CHECK_THROWS(p.discover_cure(Color::Blue)); // Player has not enough cards and no research station in the city

    CHECK_NOTHROW(p.take_card(City::Atlanta)
                    .build().build());                   // Build a research station in ATL - Building a second research station 
                                                         // Does not do anything and does not throw.

    CHECK_THROWS(p.discover_cure(Color::Yellow));       // Research station and no cards

    CHECK_NOTHROW(p.take_card(City::Beijing)
                    .fly_direct(City::Beijing)
                    .take_card(City::Beijing).take_card(City::Beijing)
                    .build());                          // Build a research station in Beijing
    CHECK_THROWS(p.fly_charter(City::Atlanta)); // Build used the Beijing card

    CHECK_NOTHROW(p.fly_shuttle(City::Atlanta)); // Two research stations are built

    // treat() before discover_cure():

    b[City::Atlanta] = 3;
    CHECK_NOTHROW(p.treat(City::Atlanta)
                    .treat(City::Atlanta)
                    .treat(City::Atlanta)); // Takes 3 treat() invokes to heal

    // discover_cure(), now that stations are built:
    CHECK_THROWS(p.discover_cure(Color::Blue));// Atlanta = Blue => Does not have enough cards

    // Needs 5 cards and to be found in a city with a station to discover a cure
    CHECK_THROWS(p.take_card(City::Atlanta).discover_cure(Color::Blue));
    CHECK_THROWS(p.take_card(City::NewYork).discover_cure(Color::Blue));
    CHECK_THROWS(p.take_card(City::SanFrancisco).discover_cure(Color::Blue));
    CHECK_THROWS(p.take_card(City::Chicago).discover_cure(Color::Blue));
    CHECK_NOTHROW(p.take_card(City::Montreal).discover_cure(Color::Blue));

    // Take 5 blue cards again and try to cure:
    CHECK_NOTHROW(take_5_blue_cards(p).discover_cure(Color::Blue));

    // Check that treat is affected by a cure the was discovered:
    // treat() after discover_cure()
    b[City::Atlanta] = 10;
    CHECK_NOTHROW(p.treat(City::Atlanta));
    CHECK_THROWS(p.treat(City::Atlanta)); // Already cleaned the disease

}

TEST_CASE("Illeagal Player operations:  ") {

    Board b;
    Player p{b, City::Atlanta};

    // Illeagal operations of any player: drive/3*fly/build/2*treat/discover_cure

    CHECK_THROWS(p.drive(City::Baghdad)); // Not connected to ATL
    CHECK_THROWS(p.drive(City::Bangkok));

    CHECK_THROWS(p.take_card(City::SaoPaulo)
                  .take_card(City::SaoPaulo) // Taking the same card twice should do NOTHING! *******
                  .fly_direct(City::SaoPaulo)// Will fly to Sao Paulo
                  .build());                 // Cannot build, no card in hand!

    CHECK_THROWS(p.take_card(City::SaoPaulo)
                   .take_card(City::SaoPaulo)   
                   .fly_charter(City::Atlanta)  // See if take_card() gives a card once 
                   .fly_direct(City::SaoPaulo));// and that fly_charter uses the card.
        
        // Player is in Atlanta

    CHECK_THROWS(p.fly_direct(City::Bangkok));  // Player does not have dest card
    CHECK_THROWS(p.fly_charter(City::Bangkok)); // Player does not have src card
    CHECK_THROWS(p.fly_shuttle(City::Bangkok)); // No research station in Bangkok nor in Atlanta

    CHECK_THROWS(p.build());                    // No city card to discard
    CHECK_THROWS(p.treat(City::Atlanta));                    // Disease level in ATL is 0
    
    CHECK_THROWS(p.treat(City::Istanbul));      // Disease level in Istanbul is 0 AND player is not in city **** ASK EREL

    b[City::Istanbul] = 1;

    CHECK_THROWS(p.treat(City::Istanbul));      // Disease level in Istanbul is 1 but player is not in city

    p.take_card(City::Istanbul).fly_direct(City::Istanbul); // Move to Istanbul

    CHECK_THROWS(p.treat(City::Bangkok));       // In Istanbul but try to treat another clean city.

    b[City::Istanbul] = 0;                              // Clear Disease

    CHECK_THROWS(p.discover_cure(Color::Blue));         // No cards in hand AND no research station - will fail
    take_5_blue_cards(p);                              
    CHECK_THROWS(p.discover_cure(Color::Blue));         // No research station - will fail

    CHECK_THROWS(p.discover_cure(Color::Black));        // try to cure BLACK disease with blue cards.
}

TEST_CASE("Medic") {
    //  If no cure is found and medic uses treat(City) - he clears the disease (disease_cube = 0)
    //  If a cure is found, he automatically clears the disease everywhere he is at, so treat() should throw
    Board b;
    Medic medic(b, City::Atlanta);

    medic.take_card(City::Atlanta).build();                         // BUILD IN ATLANTA****

    
    medic.take_card(City::HoChiMinhCity).fly_direct(City::HoChiMinhCity);   // Fly to HoChiMin
    b[City::HoChiMinhCity] = 1000;
    CHECK_NOTHROW(medic.treat(City::HoChiMinhCity)); // clears all disease
    CHECK_THROWS(medic.treat(City::HoChiMinhCity));                     // disease lv is 0, so throw

    b[City::HoChiMinhCity] = 1000;
    CHECK_NOTHROW(medic.treat(City::HoChiMinhCity));                       // clears all disease
    CHECK_THROWS(medic.treat(City::HoChiMinhCity));     // disease lv is 0, so throw


    medic.take_card(City::HoChiMinhCity).build();       // Build a Research station in HoChiMin
    take_5_blue_cards(medic).discover_cure(Color::Blue);// blue disease cure is discovered

    b[City::HoChiMinhCity] = 1000;          
    CHECK(b[City::HoChiMinhCity] == 1000); // Red disease(HoChiMin) is not automatically reduced. 
    CHECK_NOTHROW(medic.treat(City::HoChiMinhCity));          

    b[City::Atlanta] = 1000;
    b[City::Chicago] = 1000;
    b[City::SanFrancisco] = 1000;

    
    medic.fly_shuttle(City::Atlanta); // Shuttle to Atlanta and clear disease automatically(There is a research station)
    medic.drive(City::Chicago);       // Automatically clears blue disease
    medic.drive(City::SanFrancisco);  // automaticall clears blue disease
    
    CHECK(b[City::Atlanta] == 0);
    CHECK(b[City::Chicago] == 0);
    CHECK(b[City::SanFrancisco] == 0);
}

TEST_CASE("FieldDoctor") {

    Board b;
    FieldDoctor fieldDoctor(b, City::Atlanta);

    b[City::Atlanta] = 1;
    b[City::Chicago] = 1;
    b[City::Miami] = 1;
    b[City::Washington] = 1;

    CHECK_NOTHROW(fieldDoctor.treat(City::Atlanta));

    CHECK_NOTHROW(fieldDoctor.take_card(City::Chicago)
                            .treat(City::Chicago));     // Take a card and treat chicago - Card should not be used!

    CHECK_NOTHROW(fieldDoctor.drive(City::Chicago)
                            .fly_charter(City::Atlanta));   // Should have the card to use fly_charter

    CHECK_THROWS(fieldDoctor.treat(City::Chicago));         // Chicago disease lv is 0

    CHECK_NOTHROW(fieldDoctor.treat(City::Washington));     
    CHECK_NOTHROW(fieldDoctor.treat(City::Miami));

    CHECK_THROWS(fieldDoctor.treat(City::Atlanta));        // No disease
    CHECK_THROWS(fieldDoctor.treat(City::Montreal));        // No disease and not neighbor city
    CHECK_THROWS(fieldDoctor.drive(City::Chicago).treat(City::Montreal));      // Neighbors, but no disease.

}

TEST_CASE("GeneSplicer") {

    Board b;
    GeneSplicer splicer(b, City::Atlanta);

    CHECK_THROWS(splicer.discover_cure(Color::Blue));   // No research station and no cards
    splicer.take_card(City::Atlanta).build();

    CHECK_THROWS(splicer.discover_cure(Color::Blue));                            // No cards
    CHECK_THROWS(splicer.take_card(City::Chicago).discover_cure(Color::Blue));   // 1 cards
    CHECK_THROWS(splicer.take_card(City::SanFrancisco).discover_cure(Color::Blue));   // 2 cards
    CHECK_THROWS(splicer.take_card(City::Montreal).discover_cure(Color::Blue));   // 3 cards
    CHECK_THROWS(splicer.take_card(City::NewYork).discover_cure(Color::Blue));   // 4 cards
    CHECK_NOTHROW(splicer.take_card(City::Atlanta).discover_cure(Color::Yellow));   // 5 *blue* cards - should work

    CHECK_NOTHROW(take_some_5_cards(splicer).discover_cure(Color::Black));

    // Black and Yellow disease cures are discovered.

    CHECK_NOTHROW(take_some_5_cards(splicer).discover_cure(Color::Black)); // Should not throw

}

TEST_CASE("Researcher") {

    // With 5 disease color cards - can discover_cure() from anywhere.
    Board b;
    Researcher researcher(b, City::Atlanta);

    CHECK_THROWS(researcher.discover_cure(Color::Blue));                    // No cards, No station
    CHECK_THROWS(take_some_5_cards(researcher).discover_cure(Color::Blue)); // Some 5 cards - need 5 of same disease color
    CHECK_THROWS(take_5_blue_cards(researcher).discover_cure(Color::Black));// 5 Blue cards, will fail discovering black cure.
    CHECK_NOTHROW(researcher.discover_cure(Color::Blue));// Should work with 5 blue cards
    CHECK_NOTHROW(take_5_blue_cards(researcher).discover_cure(Color::Blue));// Repeating should not throw

    // Cure black disease from a blue city

    researcher.take_card(City::Baghdad)
                .take_card(City::Cairo)
                .take_card(City::Mumbai)
                .take_card(City::Tehran)
                .take_card(City::Delhi);    // Take 5 red cards

    CHECK_NOTHROW(researcher.discover_cure(Color::Black));

}

TEST_CASE("Scientist") {
    const int req_cards_to_find_cure = 4;
    Board b;
    Scientist scientist(b, City::Atlanta, req_cards_to_find_cure);

    CHECK_THROWS(scientist.discover_cure(Color::Blue)); // Not enough cards
    scientist.take_card(City::Atlanta)
                .take_card(City::NewYork)
                .take_card(City::SanFrancisco)
                .take_card(City::Chicago);
    CHECK_THROWS(scientist.discover_cure(Color::Blue)); // There is no research station
    scientist.build().take_card(City::Atlanta);         // Build and retake Atlanta card

    CHECK_NOTHROW(scientist.discover_cure(Color::Blue));    // Should work with 4 blue cards and a research station.

}   

TEST_CASE("Virologist") {
    // Can use treat(City) on every city, on city card discard.
    Board b;
    Virologist virologist(b, City::Atlanta);

    b[City::SanFrancisco] = 10; 
    b[City::Atlanta] = 2;

    // Treating in current City:
    CHECK_NOTHROW(virologist.treat(City::Atlanta)); 
    CHECK(b[City::Atlanta] == 1); // Check disease lv reduced by 1.
    CHECK_THROWS(virologist.treat(City::Atlanta));  // No city card. **** SHOULD THAT THROW ?
    CHECK_NOTHROW(virologist.take_card(City::Atlanta)
                            .treat(City::Atlanta));  // Has a city card.
    
    CHECK_THROWS(virologist.fly_charter(City::Delhi));  // Should not have a city card to fly, Checks that it was used.
    CHECK_NOTHROW(virologist.take_card(City::SanFrancisco).treat(City::SanFrancisco));
    CHECK(b[City::SanFrancisco] == 9);

    virologist.take_card(City::Atlanta).build();                        // Build a research station
    take_5_blue_cards(virologist).discover_cure(Color::Blue);           // Discover blue disease cure

    virologist.take_card(City::HongKong).fly_direct(City::HongKong);    // Fly to a red country

    CHECK_NOTHROW(virologist.take_card(City::SanFrancisco).treat(City::SanFrancisco));

}

TEST_CASE("Dispatcher") {
    Board b;
    Dispatcher        dispatcher(b, City::Atlanta);

    dispatcher.take_card(City::Atlanta).build();            // Build a research station - can fly_direct anywhere

    CHECK_NOTHROW(dispatcher.fly_direct(City::Santiago));       
    CHECK_THROWS(dispatcher.fly_direct(City::Atlanta));             // No research station
    dispatcher.take_card(City::Atlanta).fly_direct(City::Atlanta);      // Return to ATL
    CHECK_NOTHROW(dispatcher.fly_direct(City::Atlanta));            // Should be able to fly - research station
}

TEST_CASE("OperationsExpert") {

    Board b;
    OperationsExpert  operExpert(b, City::Atlanta);

    CHECK_NOTHROW(operExpert.build());      // Build a Research station without using a card.    in ATL.
    // CHECK_THROWS(operExpert.build());       // Only one research station could be built in a city. 
                                               // UPDATE: build() second researcher station does not throw

    operExpert.take_card(City::London).fly_direct(City::London);        // Fly to London

    CHECK_NOTHROW(operExpert.take_card(City::London)
                            .build()
                            .fly_charter(City::Atlanta)); // Build station and go back to ATL with one card
}