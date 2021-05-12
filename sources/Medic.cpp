#include "Medic.hpp"

using namespace std;

namespace pandemic {
    Medic::Medic(Board& board, City city):  Player(board, city){}
    Medic& Medic::treat(const City city){
        if(city == curr_city) {
            cout << b[city] << endl;
            if(b[city] > 0){
                b[city] = 0;
                // std::cout << "treat in city "<<  getCityAsString(city) << " is down to 0\n";
            }else{
                // std::cout << "treat in city "<<  getCityAsString(city) << " is Fails Because the disease_level = 0\n";
                throw invalid_argument{"ERROR - treat in city "+getCityAsString(city)+" is Fails Because the disease_level = 0"};
            }
        }else{
            throw invalid_argument{"ERROR - Player Cannot treat outside of his current city"};
        }
        //  cout << "Medic -> treat()" << endl;
        return *this;
    }
    Medic& Medic::drive(const City city){
        Player::drive(city);
        if(b.is_cure(city)){
            b[city] = 0;
        }
        return *this;
    }
    Medic& Medic::fly_charter(const City city){
        Player::fly_charter(city);
        if(b.is_cure(city)){
            b[city] = 0;
        }
        return *this;
    }
    Medic& Medic::fly_shuttle(const City city){
        Player::fly_shuttle(city);
        if(b.is_cure(city)){
            b[city] = 0;
        }
        return *this;
    }
    Medic& Medic::fly_direct(const City city){
        Player::fly_direct(city);
        if(b.is_cure(city)){
            b[city] = 0;
        }
        return *this;
    }
    std::string Medic::role(){
        return "Medic";
    }
}










