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
            Player& build() {
                std::cout << "build() override OperationsExpert" << std::endl;
                if (cards[curr_city] == true) {
                    Player::build();
                    cards[curr_city] = true; 
                }else{
                    cards[curr_city] = true; 
                    Player::build();
                }

                
                 return *this;}
            // Player& drive(City city){return *this;}
            // Player& fly_charter(City city){return *this;}
            // Player& fly_shuttle(City city){return *this;}
            // Player& fly_direct(City city){return *this;}
    };
}