#pragma once

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <vector>
namespace pandemic{
    class Researcher : public Player{
         public:
            Researcher(Board&, City);
            Researcher& discover_cure(const Color) override ;// ~Researcher(){}
            std::string role() override ;
    };
}