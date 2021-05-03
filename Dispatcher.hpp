#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
namespace pandemic{
    class Dispatcher : public Player{
        std::string name;
        
         public:
            Dispatcher(Board& board, City city): Player(board, city) , name("Dispatcher"){}
            ~Dispatcher(){}
            Player& fly_direct(City city)override{std::cout << "fly_direct() override Dispatcher" << std::endl; return *this;}
            std::string role() override{std::cout << "role() override Dispatcher" << std::endl; return "role() override Dispatcher";}

    };
}