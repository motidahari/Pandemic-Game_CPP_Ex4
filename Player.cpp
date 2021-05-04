#include "Player.hpp"
using namespace std;
namespace pandemic {

        Player::Player(Board& board, City city):b(board), curr_city(city){
                for(const auto &x : board.getVertex()){
                        cards[x.first] = false;
                }
        }
        Player& Player::build(){ 
                if(cards[curr_city] == true || b.getVertex()[curr_city].research_station == true){
                        b.getVertex()[curr_city].research_station = true;
                        cards[curr_city] = false;
                }else{
                    throw invalid_argument{"ERROR - You are not in the city where you want to build a research station"};       
                }
                cout << "build\n";
                
                return *this;
        }
        Player& Player::fly_charter(City city) {
                cout << "fly_charter -> cards["<< getCityAsString(curr_city) <<"] = " << cards[curr_city] << endl;
                if(cards[curr_city] == true){
                        cards[curr_city] = false;
                        curr_city = city;
                        cout << "after change fly_charter -> cards["<< getCityAsString(curr_city) <<"] = " << cards[curr_city] << endl;

                }else{
                        throw invalid_argument{"ERROR - It is not possible to move to the requested city because the city card is not in the cards in your hand"};   
                }

                cout << "fly_charter\n"; 
                return *this;
                }
        Player& Player::drive(City city){ 
                if(b.is_connected(curr_city,city) || curr_city == city ){
                        curr_city = city;
                }else{
                     throw invalid_argument{"ERROR - The cities are not connected"};   
                }
                cout << "drive\n";
                return *this;
        }
        Player& Player::fly_shuttle(City city){ 
                // cout << " b.getVertex()["<< getCityAsString(curr_city) << "].research_station = " << b.getVertex()[curr_city].research_station; 
                // cout << " b.getVertex()["<< getCityAsString(city) << "].research_station = " << b.getVertex()[city].research_station; 
                if(b.getVertex()[curr_city].research_station == true &&  b.getVertex()[city].research_station == true){
                       curr_city = city;
                }else{
                   throw invalid_argument{"ERROR - It is not possible to move to the requested city because there is no research station in your city or there is no research station in the city you requested"};           
                }
                cout << "fly_shuttle\n";
                return *this;
        }
        Player& Player::take_card(City city){ 
                cout << "take_card\n";
                cards[city] = true;
                return *this;
        }
        std::string Player::role() {cout << "role() base Player\n"; return "Base Player"; }
        Player& Player::fly_direct(City city){ 
                cout << "fly_direct -> cards["<<  getCityAsString(city) <<"] = " << cards[city] << endl;
                if(cards[city] == true){
                        curr_city = city;
                        cards[city] = false;
                        cout << "after change fly_direct -> cards["<<  getCityAsString(city) <<"] = " << cards[city] << endl;

                }else{
                     throw invalid_argument{"ERROR - It is not possible to move to the requested city because the city card is not in the cards in your hand"};      
                }
                
                cout << "fly_direct\n";return *this;
        }
        Player& Player::discover_cure(Color color){
                int count = 0;
                City city[5] = {};
                if(b.getVertex()[curr_city].research_station == true){
                        for(const auto &x : cards){
                                if(count == 5){
                                        break;
                                }
                                if(b.getVertex()[x.first].color == color && cards[x.first] == true){
                                        // ;
                                        *(city + count) = x.first;
                                        count++;
                                        // cards[x.first] = false;
                                }
                        }
                }
                if(count == 5){
                        for(const auto &x : city){
                           cards[x] = false;     
                        }
                        b.set_Cure_discovered(color);
                }else if(count < 5){
                        cout << "count = " << count << "\n";
                        throw invalid_argument{"ERROR - the amount of cards you have in the color you wanted is less than 5"};
                }else{
                        throw invalid_argument{"ERROR - There is no research station in the requested city"};
                }  
                return *this;              
                
        }

        Player& Player::treat(City city){
                if(city == curr_city && b[city] > 0) {
                        if(b.getCure_discovered()[b.getVertex()[city].color] == true){
                                b.getVertex()[city].disease_level = 0;
                                return *this;
                        }else if(b.getVertex()[city].disease_level == 0){
                                throw invalid_argument{"ERROR - Attempt to decrease the disease was unsuccessful, because the disease_level is already 0"};
                        }
                        --b.getVertex()[city].disease_level;
                        cout << "treat\n";return *this;
                }else{
                        throw invalid_argument{"ERROR - Player Cannot treat outside of his current city"};
                }
                
        }	
}









