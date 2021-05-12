#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <vector>

namespace pandemic{
    class GeneSplicer : public Player{

         public:
            GeneSplicer(Board&, City);
            GeneSplicer& discover_cure(const Color) override ;
            std::string role() override ;
    };
}