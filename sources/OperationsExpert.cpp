#include "OperationsExpert.hpp"


using namespace std;
namespace pandemic {
    OperationsExpert::OperationsExpert(Board& board, City city):  Player(board, city){}
    Player& OperationsExpert::build() {
        // std::cout << "build() override OperationsExpert" << std::endl;
        if (cards[curr_city]) {
            Player::build();
            cards[curr_city] = true; 
        }else{
            cards[curr_city] = true; 
            Player::build();
        }
        return *this;
    }
    std::string OperationsExpert::role(){
        return "OperationsExpert";
    }
};
