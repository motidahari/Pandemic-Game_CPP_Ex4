#include "Dispatcher.hpp"


using namespace std;
namespace pandemic {
    Dispatcher::Dispatcher(Board& board, City city):  Player(board, city){}
    Dispatcher& Dispatcher::fly_direct(const City city) {
        if(b.getVertex()[curr_city].research_station){
            if (cards[city]) {
                Player::fly_direct(city);
                cards[city] = true; 
            }else{
                cards[city] = true; 
                Player::fly_direct(city);
            }
        }else{
            Player::fly_direct(city);
        }
        return *this;
    }
    std::string Dispatcher::role() {
            return "Dispatcher"; 
    }
};
