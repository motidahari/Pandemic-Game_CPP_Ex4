#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace pandemic{
    class GeneSplicer : public Player{
        std::string name;

         public:
            GeneSplicer(Board& board, City city): Player(board, city) , name("GeneSplicer"){}
            // ~GeneSplicer(){}
            // Player& discover_cure(Color color)  {std::cout << "discover_cure() override GeneSplicer" << std::endl; return *this;}
            // std::string role() {std::cout << "role() override GeneSplicer" << std::endl; return "role() override GeneSplicer";}

    };
}