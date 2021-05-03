#pragma once
#include "City.hpp"
#include "Color.hpp"
// #include "Board.cpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic{
    class Board {

          std::map<City, std::set<City>> Neighbors_graph;
          std::map<City, int> Disease_level;
        //   std::set<City,int> Disease_level_get;
          std::set<City> Research_station;
          std::map<Color, bool> Cure_discovered;

        
        public:
            Board(){}
            ~Board(){}
            int& operator[](City city);
            const int operator[](City city) const ;
            bool is_clean();
            // void remove_cures();
            friend std::ostream& operator<<(std::ostream& os ,const Board& board);
    };
}