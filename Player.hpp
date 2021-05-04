#pragma once

#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {

    class Player {
        protected:
            Board& b;
            City curr_city;
            std::map<City, bool> cards;
        public: 

            Player(Board&, City);

            Player& fly_charter(City);
            Player& drive(City city);
            Player& fly_shuttle(City city);
            Player& take_card(City c);

            virtual Player& build();
            virtual std::string role();
            virtual Player& fly_direct(City city);
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City c);
    };
}