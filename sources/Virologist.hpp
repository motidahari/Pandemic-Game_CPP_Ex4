#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include "Board.hpp"

namespace pandemic{
    class Virologist : public Player{
         public:
            Virologist(Board&, City) ;
            Virologist& treat(const City) override ;
            std::string role() override ;
    };
}