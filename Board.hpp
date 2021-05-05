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
        private:
            std::map<City, Node> vertex;
            std::map<Color, bool> Cure_discovered;
        public:
            Board(){
                std::ifstream cities_file{"cities_map.txt"};
                initColor();
                initGraph(cities_file);
            }

            int& operator[](City city);

            bool is_connected(const City city1,const City city2);
            bool is_clean();

            void set_Cure_discovered(Color color);
            void remove_cures();
            void printMap();
            
            void printCure_discovered();
            void initGraph(std::ifstream& cities_file);
            void initColor();
            std::map<City, Node>& getVertex(){
                return this->vertex;
            }
            std::map<Color, bool>& getCure_discovered(){
                return this->Cure_discovered;
            }
            friend std::ostream& operator<<(std::ostream&,const Board&);


    };
}

