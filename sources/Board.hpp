#pragma once
#include "City.hpp"
#include "Color.hpp"
// #include "Board.cpp"
#include <map>
#include <set>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

namespace pandemic{
    struct Node {
        Color color;
        std::set<City> neighbors;
        int disease_level;
        bool research_station;
    };
    class Board {
        protected:
            std::map<City, Node> vertex;
            std::map<Color, bool> Cure_discovered;
        public:
            Board();
            int& operator[](City city);

            bool is_connected(const City ,const City);
            bool is_clean();
            bool is_cure(const City city);
            
            void set_Cure_discovered(const Color);
            void remove_cures();
            void remove_stations();
            void printMap();
            void printCure_discovered();
            void initGraph(std::ifstream&);
            void initColor();

            std::map<City, Node>& getVertex();
            std::map<Color, bool>& getCure_discovered();

            friend std::ostream& operator<<(std::ostream&,const Board&);
    };
}

