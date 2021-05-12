#include "Virologist.hpp"

using namespace std;
namespace pandemic {
    Virologist::Virologist(Board& board, City city):  Player(board, city){}
    Virologist& Virologist::treat(const City city){
        if(city == curr_city){
            Player::treat(city);
        }else if(cards[city]){
            City temp = curr_city;
            curr_city = city;
            Player::treat(city);
            curr_city = temp;
            cards[city] = false;
            // std::cout << "treat for city ("<< getCityAsString(city) << ") is Succeeded"<< endl;
        }else{
            // std::cout << "you dont have the card of the city" << getCityAsString(city) << endl;
            throw invalid_argument{"ERROR - you dont have the card of the city "+getCityAsString(city)};
        }
        return *this;
    }
    std::string Virologist::role(){
        return "Virologist";
    }
}










