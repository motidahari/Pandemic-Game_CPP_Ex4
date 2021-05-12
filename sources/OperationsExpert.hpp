#pragma once
#include <iostream>

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class OperationsExpert : public Player{            
        public:
            OperationsExpert(Board&, City);
            Player& build() override;
            std::string role() override;
    };
}