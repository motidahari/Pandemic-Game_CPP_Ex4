#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include "Board.hpp"

namespace pandemic{
    class Virologist : public Player{
        std::string name;
        
         public:
            Virologist(Board& board, City city): Player(board, city) , name("Virologist"){}
            ~Virologist(){}
            Player& treat(City c) override{std::cout << "treat() override Virologist" << std::endl; return *this;}
            std::string role() override{std::cout << "role() override Virologist" << std::endl; return "role() override Virologist";}


    };
}