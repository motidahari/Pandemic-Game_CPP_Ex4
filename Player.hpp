#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{


    class Player{
        Board& board;
        City city;
        std::set<City> cards;
    public:
        Player(Board& board, City city): board(board), city(city){}
        // Player(Board& b, City c):board(b), city(c) {std::cout << "Player constructor\n"; }
        inline ~Player(){};

        Player& fly_charter(City);
        Player& drive(City city);
        Player& fly_shuttle(City city);
        Player& take_card(City c);
        void foo() const {std::cout << "foo()\n";}
        virtual std::string role();
        virtual Player& fly_direct(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City c);
        
    };
}