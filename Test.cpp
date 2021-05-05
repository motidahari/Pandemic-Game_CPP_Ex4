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
#include <vector>

using namespace std;
using namespace pandemic;
const vector<string> cities {"Algiers","Atlanta","Baghdad","Bangkok","Beijing","Bogota","BuenosAires","Cairo","Chennai","Chicago","Delhi","Essen","HoChiMinhCity","HongKong","Istanbul","Jakarta","Johannesburg","Karachi","Khartoum","Kinshasa","Kolkata","Lagos","Lima","London","LosAngeles","Madrid","Manila","MexicoCity","Miami","Milan","Montreal","Moscow","Mumbai","NewYork","Osaka","Paris","Riyadh","SanFrancisco","Santiago","SaoPaulo","Seoul","Shanghai","StPetersburg","Sydney","Taipei","Tehran","Tokyo","Washington"};    // namespace pandemic{
const vector<string> cities_in_Black {"Bogota","BuenosAires","Johannesburg","Khartoum","Kinshasa","Lagos","Lima","LosAngeles","MexicoCity","Miami","Santiago","SaoPaulo"};
const vector<string> cities_in_Blue {"Atlanta","Chicago","Essen","London","Madrid","Milan","Montreal","NewYork","Paris","SanFrancisco","StPetersburg","Washington"};
const vector<string> cities_in_Red {"Bangkok","Beijing","HoChiMinhCity","HongKong","Jakarta","Manila","Osaka","Seoul","Shanghai","Sydney","Taipei","Tokyo"};
const vector<string> cities_in_Yellow {"Bogota","BuenosAires","Johannesburg","Khartoum","Kinshasa","Lagos","Lima","LosAngeles","MexicoCity","Miami","Santiago","SaoPaulo"};
    Board board;
    /**
     * checke if two vertex are connected
    */
    bool is_connected(City city1, City city2) {
        return board.getVertex()[city1].neighbors.count(city2) > 0 && board.getVertex()[city2].neighbors.count(city1) > 0;
    }
    /**
     * get random ni of some city 
    */
    City getRandomCity() {
        unsigned randomm = (unsigned)(rand() % 48);  
        return getCityAsObject(cities.at(randomm));
    }



int numRun = 100;
TEST_CASE("Test for operator[] in Board class"){
    City randCity;
     for (size_t i = 0; i < numRun; i++){
        int r = rand() % 100; 
        CHECK_NOTHROW(board[(randCity = getRandomCity())] = r);
        CHECK_EQ(board[randCity],r);
        CHECK_NOTHROW(board[randCity]--);
        CHECK_EQ(board[randCity],--r);
        CHECK_NOTHROW(board[randCity]++);
        CHECK_EQ(board[randCity],++r);
        CHECK_NOTHROW(board[randCity] += r);
        CHECK_EQ(board[randCity],r += r);
        CHECK_NOTHROW(board[randCity] -= r);
        CHECK_EQ(board[randCity],r -= r);
    }
}

TEST_CASE("Test for is_clean() in class Board"){
    City randCity;
    for (size_t i = 0; i < numRun; i++){
        int r = (rand() % 150) + 1; 
        CHECK_NOTHROW(board[(randCity = getRandomCity())] = r);
        CHECK_EQ(board[randCity],r);
        CHECK_EQ(board.is_clean(), false);
    }
    for(const auto& city: cities) {
        board[getCityAsObject(city)] = 0;
    }
    CHECK(board.is_clean() == true);
}

TEST_CASE("Test for class Player"){
    City randCity;
    Player player{board, City::Atlanta};
    CHECK_THROWS(player.build());
    //check build
    for (size_t i = 0; i < numRun; i++){
        player.take_card((randCity = getRandomCity()));
        if((City::Atlanta == player.getCurrCity()) && player.checkCardByCity(player.getCurrCity()) == true){
            CHECK_NOTHROW(player.build());
        }else if(City::Atlanta != player.getCurrCity()){
            CHECK_THROWS(player.build());
        }
    }
    //check drive to ni
    for(const auto& x: board.getVertex()){
        for(const auto& ni: board.getVertex()[City::Atlanta].neighbors){ 
            Player player{board, City::Atlanta};
            // player.drive();
            CHECK_NOTHROW(player.drive(ni););
        }   
    }
    //check drive to not ni and not the same city
    for(const auto& x: board.getVertex()){
        Player player{board, City::Atlanta};
        if(board.is_connected(City::Atlanta,x.first) == false && City::Atlanta != x.first){
            CHECK_THROWS(player.drive(x.first));
        }
    }



}









