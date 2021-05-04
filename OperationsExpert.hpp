#pragma once
#include <iostream>

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class OperationsExpert : public Player{
        private:
            
        public:
            // OperationsExpert(Board& board, City city): Player(board, city, "OperationsExpert") {}
            OperationsExpert(Board& board, City city):  Player(board, city){}
            Player& build() {std::cout << "build() override OperationsExpert" << std::endl; return *this;}
    };
}