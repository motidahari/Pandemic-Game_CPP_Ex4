#include "Researcher.hpp"
using namespace std;
const int num5 =  5;
namespace pandemic {
    Researcher::Researcher(Board& board, City city):  Player(board, city){}
    Researcher& Researcher::discover_cure(const Color color) {
        if(b.getCure_discovered()[color]){
        //     std::cout << "There is already a cure for the disease\n";
            return *this;   
        }
        u_int count = 0;
        vector<City> city(num5);
        for(const auto &x : cards){
                if(count == num5){
                        break;
                }
                if(b.getVertex()[x.first].color == color && cards[x.first]){
                        city.at(count) = x.first;
                        count++;
                }
        }
        if(count == num5){
                for(const auto &x : city){
                    cards[x] = false;     
                }
                // std::cout << "discover_cure in color "<<  getColorAsString(color) << " is Succeeded\n";
                b.set_Cure_discovered(color);
        }else if(count < num5){
                // std::cout << "the amount of cards you have in the color you wanted is less than 5 "<<  getColorAsString(color) << "\n";
                throw invalid_argument{"ERROR - the amount of cards you have in the color you wanted is less than 5"};
        }  
        return *this;  
    }
    std::string Researcher::role(){
        return "Researcher";
    }

};