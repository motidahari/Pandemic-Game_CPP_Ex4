#include "GeneSplicer.hpp"
using namespace std;
const int num5 =  5;
namespace pandemic {
    GeneSplicer::GeneSplicer(Board& board, City city):  Player(board, city){}
    GeneSplicer& GeneSplicer::discover_cure(const Color color){
       if(b.getCure_discovered()[color]){
                // std::cout << "There is already a cure for the disease\n";
                return *this;   
        }
        u_int count = 0;
        vector<City> city(num5);
        if(b.getVertex()[curr_city].research_station){  
                for(const auto &x : cards){
                        if(count == num5){
                                break;
                        }
                        if(cards[x.first]){
                                city.at(count) = x.first;
                                count++;
                        }
                }
        }else{
                // std::cout << "There is no research station in the requested city" <<"\n";
                throw invalid_argument{"ERROR - There is no research station in the requested city"};
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
    std::string GeneSplicer::role(){
            return "GeneSplicer"; 
    }    
};