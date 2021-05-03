#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace pandemic{
    class Scientist : public Player{
        std::string name;
        int n;
        
         public:
            Scientist(Board& board, City city): Player(board, city) , name("Scientist"){}
            Scientist(Board& board, City city, int n): Player(board, city) , name("Scientist"), n(n){}
            ~Scientist(){}
            Player& discover_cure(Color color) override{std::cout << "discover_cure() override Scientist" << std::endl; return *this;}
            std::string role() override{std::cout << "role() override Scientist" << std::endl; return "role() override Scientist";}

    };
}