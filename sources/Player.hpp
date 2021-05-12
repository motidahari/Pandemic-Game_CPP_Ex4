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
            std::string name;
            std::map<City, bool> cards;
        public: 
            Player(Board&, City);

            Player& take_card(const City);
            Player& remove_cards();

            City getCurrCity();

            Board& getBoard();

            bool checkCardByCity(const City);
            void printAllCards();
            void removeAllCards();
            
            virtual Player& fly_charter(const City);
            virtual Player& drive(const City);
            virtual Player& fly_shuttle(const City);
            virtual Player& build();
            virtual std::string role();
            virtual Player& fly_direct(const City);
            virtual Player& discover_cure(const Color);
            virtual Player& treat(const City);
    };
}