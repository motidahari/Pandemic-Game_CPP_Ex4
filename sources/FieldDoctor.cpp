#include "FieldDoctor.hpp"
using namespace std;
// const int num5 =  5;
namespace pandemic {
    FieldDoctor::FieldDoctor(Board& board, City city):  Player(board, city){}
    FieldDoctor& FieldDoctor::treat(const City city){
        if( city == curr_city || b.is_connected(curr_city,city)) {
            City temp = curr_city;
            curr_city = city;
            Player::treat(city);
            curr_city = temp;
            // std::cout << "treat for city ("<< getCityAsString(city) << ") is Succeeded"<< endl;
        }else{
            Player::treat(city);
        }
        return *this;   
    }
    std::string FieldDoctor::role() {
            return "FieldDoctor"; 
    }

}











