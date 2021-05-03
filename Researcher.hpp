#pragma once

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
namespace pandemic{
    class Researcher : public Player{
        std::string name;

         public:
            Researcher(Board& board, City city):Player(board, city) , name("Researcher"){}
            ~Researcher(){}
            Player& discover_cure(Color color) override{std::cout << "discover_cure() override Researcher" << std::endl; return *this;}
            std::string role() override{std::cout << "role() override Researcher" << std::endl; return "role() override Researcher";}

    };
}