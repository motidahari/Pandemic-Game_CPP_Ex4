#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
        #include <iostream>
namespace pandemic{
    class Medic : public Player{
        std::string name;

         public:
            Medic(Board& board, City city): Player(board, city) , name("Medic"){}
            Player& treat(City c) override;
            std::string role() override;
    };
}