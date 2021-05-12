#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <vector>

namespace pandemic{
    class Scientist : public Player{
        u_int numOfCards;
         public:
            Scientist(Board&, City , int );
            Scientist& discover_cure(const Color) override ;
            std::string role() override ;

    };
}