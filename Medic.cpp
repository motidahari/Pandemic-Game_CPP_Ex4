#include "Medic.hpp"

using namespace std;
namespace pandemic {
    
     Player& Medic::treat(City city){
         if(city == curr_city && b[city] > 0) {
                if(b.getCure_discovered()[b.getVertex()[city].color]){
                        b.getVertex()[city].disease_level = 0;
                }else if(b.getVertex()[city].disease_level == 0){
                        throw invalid_argument{"ERROR - Attempt to decrease the disease was unsuccessful, because the disease_level is already 0"};
                }
                b.getVertex()[city].disease_level = 0;
                }else{
                    throw invalid_argument{"ERROR - Player Cannot treat outside of his current city"};
                }
        //  cout << "Medic -> treat()" << endl;
        return *this;
    }


    Player& Medic::drive(City city){ 
        Player::drive(city);
        if(b.getCure_discovered()[b.getVertex()[city].color]){
            b.getVertex()[city].disease_level = 0;
        }
        cout << "Medic -> drive Medic\n";
        return *this;
    }
    Player& Medic::fly_direct(City city){ 
        Player::fly_direct(city);
        if(b.getCure_discovered()[b.getVertex()[city].color]){
            b.getVertex()[city].disease_level = 0;
        }
        cout << "Medic -> fly_direct\n";
        return *this;

    }
    Player& Medic::fly_charter(City city) {
        Player::fly_charter(city);
        if(b.getCure_discovered()[b.getVertex()[city].color] ){
            b.getVertex()[city].disease_level = 0;
        }
        cout << "Medic -> fly_charter\n"; 
        return *this;
    }
    Player& Medic::fly_shuttle(City city){ 
        Player::fly_shuttle(city);
        if(b.getCure_discovered()[b.getVertex()[city].color]){
            b.getVertex()[city].disease_level = 0;
        }
        cout << "Medic -> fly_shuttle\n";
        return *this;
    }
}










