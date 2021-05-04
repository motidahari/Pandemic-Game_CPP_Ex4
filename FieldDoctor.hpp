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
            Player& treat(City city);
            // Player& drive(City city); 
            // Player& fly_charter(City city);
            // Player& fly_shuttle(City city);
            // Player& fly_direct(City city);
            // ~FieldDoctor(){}

            // Player& treat(City c)  {std::cout << "treat() override FieldDoctor" << std::endl; return *this;}
            // std::string role() {std::cout << "role() override FieldDoctor" << std::endl; return "role() override FieldDoctor";}

    };
}