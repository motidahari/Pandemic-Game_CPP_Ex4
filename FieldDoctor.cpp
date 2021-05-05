#include "FieldDoctor.hpp"

using namespace std;
namespace pandemic {
    
     Player& FieldDoctor::treat(City city){
        if(b.is_connected(curr_city,city)){
            if(b.getCure_discovered()[b.getVertex()[city].color] ){
                b.getVertex()[city].disease_level = 0;
            }else{
                b.getVertex()[city].disease_level--;
            }
        }else{
            throw invalid_argument{"ERROR - treat -> FieldDoctor"};
        }
        cout << "FieldDoctor -> treat()" << endl;
        return *this;
    }


    // Player& Medic::drive(City city){ 
    //     Player::drive(city);
    //     if(b.getCure_discovered()[b.getVertex()[city].color] == true){
    //         b.getVertex()[city].disease_level = 0;
    //     }
    //     cout << "Medic -> drive Medic\n";
    //     return *this;
    // }
    // Player& Medic::fly_direct(City city){ 
    //     Player::fly_direct(city);
    //     if(b.getCure_discovered()[b.getVertex()[city].color] == true){
    //         b.getVertex()[city].disease_level = 0;
    //     }
    //     cout << "Medic -> fly_direct\n";
    //     return *this;

    // }
    // Player& Medic::fly_charter(City city) {
    //     Player::fly_charter(city);
    //     if(b.getCure_discovered()[b.getVertex()[city].color] == true){
    //         b.getVertex()[city].disease_level = 0;
    //     }
    //     cout << "Medic -> fly_charter\n"; 
    //     return *this;
    // }
    // Player& Medic::fly_shuttle(City city){ 
    //     Player::fly_shuttle(city);
    //     if(b.getCure_discovered()[b.getVertex()[city].color] == true){
    //         b.getVertex()[city].disease_level = 0;
    //     }
    //     cout << "Medic -> fly_shuttle\n";
    //     return *this;
    // }
}











