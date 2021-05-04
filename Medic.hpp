#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace pandemic{
    class Medic : public Player{
        std::string name;

         public:
            Medic(Board& board, City city): Player(board, city) , name("Medic"){}
            Player& treat(City city);
            Player& drive(City city); 
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            Player& fly_direct(City city);
            // std::string role() {return "Medic";}
    };
}