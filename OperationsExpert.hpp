#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <iostream>
#include "Board.hpp"

namespace pandemic{
    class OperationsExpert : public Player{
        std::string name;
         public:
            // OperationsExpert(Board& board, City city): Player(board, city, "OperationsExpert") {}
            OperationsExpert(Board& board, City city):  Player(board, city), name("OperationsExpert"){}
            ~OperationsExpert(){}
            Player& build() override {std::cout << "build() override OperationsExpert" << std::endl; return *this;}
            std::string role() override {std::cout << "role() override OperationsExpert" << std::endl; return "role() override OperationsExpert";}
            
            

    };
}