#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace pandemic{
    class FieldDoctor : public Player{
        std::string name;
        
         public:
            FieldDoctor(Board& board, City city): Player(board, city) , name("FieldDoctor"){} 
            ~FieldDoctor(){}

            Player& treat(City c) override {std::cout << "treat() override FieldDoctor" << std::endl; return *this;}
            std::string role() override{std::cout << "role() override FieldDoctor" << std::endl; return "role() override FieldDoctor";}

    };
}