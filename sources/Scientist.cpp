#include "Scientist.hpp"

using namespace std;
namespace pandemic {
    Scientist::Scientist(Board& board, City city, int n):  Player(board, city), numOfCards((u_int)n){}
    Scientist& Scientist::discover_cure(const Color color) {
        if(b.getCure_discovered()[color]){
        //     std::cout << "There is already a cure for the disease\n";
            return *this;   
        }
        u_int count = 0;
        // u_int n = numOfCards
        vector<City> city(numOfCards);
        if(b.getVertex()[curr_city].research_station){  
                for(const auto &x : cards){
                        if(count == numOfCards){
                                break;
                        }
                        if(b.getVertex()[x.first].color == color && cards[x.first]){
                                city.at(count) = x.first;
                                count++;
                        }
                }
        }else{
                // std::cout << "There is no research station in the requested city" <<"\n";
                throw invalid_argument{"ERROR - There is no research station in the requested city"};
        }
        if(count == numOfCards){
                for(const auto &x : city){
                    cards[x] = false;     
                }
                // std::cout << "discover_cure in color "<<  getColorAsString(color) << " is Succeeded\n";
                b.set_Cure_discovered(color);
        }else if(count < numOfCards){
                // cout << "count = " << count << "\n";
                // std::cout << "the amount of cards you have in the color you wanted is less than "<< numOfCards <<" "<<  getColorAsString(color) << "\n";
                throw invalid_argument{"ERROR - the amount of cards you have in the color you wanted is less than 5"};
        }  
        return *this;     
    }
    std::string Scientist::role(){
        return "Scientist";
    }

};