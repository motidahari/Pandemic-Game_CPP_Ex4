#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
namespace pandemic{
    class Dispatcher : public Player{
        public:
            Dispatcher(Board&, City);
            Dispatcher& fly_direct(const City) override ;
            std::string role() override ;
    };
}