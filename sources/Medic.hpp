#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace pandemic{
    class Medic : public Player{

         public:
            Medic(Board& board, City city);
            Medic& treat(const City city) override ;
            Medic& drive(const City city) override ; 
            Medic& fly_charter(const City city) override ;
            Medic& fly_shuttle(const City city) override ;
            Medic& fly_direct(const City city) override ;
            std::string role() override ;
    };
}