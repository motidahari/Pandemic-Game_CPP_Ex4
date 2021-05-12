#include "Player.hpp"
#include <vector>

using namespace std;
const int num5 =  5;
namespace pandemic {

        Player::Player(Board& board, City city):b(board), curr_city(city), name("player"){
                for(const auto &x : board.getVertex()){
                        cards[x.first] = false;
                }
        }
        Player& Player::build(){
                if(cards[curr_city] || b.getVertex()[curr_city].research_station){
                        if(!b.getVertex()[curr_city].research_station){
                                // std::cout << "build in city "<<  getCityAsString(curr_city) << "is Succeeded\n";
                                b.getVertex()[curr_city].research_station = true;
                                cards[curr_city] = false;
                        }else{
                                // std::cout << "there was research_station in the city "<<  getCityAsString(curr_city) << "so we dont do nothing\n";     
                        }
                }else{
                        // std::cout << "build in city "<<  getCityAsString(curr_city) << " is Fails\n";
                        throw invalid_argument{"ERROR - You are not in the city where you want to build a research station"};       
                }
                // cout << "build\n";
                
                return *this;
        }
        Player& Player::drive(const City city){ 
                if(b.is_connected(curr_city,city)){
                        // std::cout << "drive from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << "is Succeeded\n";
                        curr_city = city;
                }else{
                        // std::cout << "drive from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << "is Fails\n";
                        throw invalid_argument{"ERROR - The cities are not connected"};   
                }
                return *this;
        }
        Player& Player::fly_direct(const City city){ 
                if(cards[city]){
                        if(curr_city != city){
                                // std::cout << "fly_direct from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << " is Succeeded\n";
                                cards[city] = false;
                                curr_city = city;  
                        }else{
                             throw invalid_argument{"ERROR - It is not possible to fly from city to it self"};           
                        }
                        
                }else{
                        // std::cout << "fly_direct from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << " is Fails\n";
                        throw invalid_argument{"ERROR - It is not possible to move to the requested city because the city card is not in the cards in your hand"};      
                }
                return *this;
        }
        Player& Player::fly_charter(const City city) {
                // cout << "fly_charter in Medic and the city is = " << getCityAsString(curr_city)<< endl;
                // cout << "cards[" << getCityAsString(curr_city) << "] = " << cards[curr_city] << endl;
                // cout << "fly_charter -> cards["<< getCityAsString(curr_city) <<"] = " << cards[curr_city] << endl;
                if(cards[curr_city]){
                        cout << "fly_charter from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << "is Succeeded\n";
                        cards[curr_city] = false;
                        curr_city = city;
                        // cout << "after change fly_charter -> cards["<< getCityAsString(curr_city) <<"] = " << cards[curr_city] << endl;
                }else{
                        // std::cout << "fly_charter from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << "is Fails\n";
                        throw invalid_argument{"ERROR - It is not possible to move to the requested city because the city card is not in the cards in your hand"};   
                }

                // cout << "fly_charter\n"; 
                return *this;
        }
        Player& Player::fly_shuttle(const City city){ 
                if(b.getVertex()[curr_city].research_station &&  b.getVertex()[city].research_station ){
                        if(curr_city != city){
                                // std::cout << "fly_shuttle from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << " Succeeded\n";
                                curr_city = city;
                        }else{
                             throw invalid_argument{"ERROR - It is not possible to fly from city to it self"};           
                        }
                        
                }else{
                        // std::cout << "fly_shuttle from "<<  getCityAsString(curr_city) << " to " << getCityAsString(city) << " Fails\n";
                        throw invalid_argument{"ERROR - It is not possible to move to the requested city because there is no research station in your city or there is no research station in the city you requested"};           
                }
                // cout << "fly_shuttle\n";
                return *this;
        }
        Player& Player::discover_cure(const Color color){
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
                                if(b.getVertex()[x.first].color == color && cards[x.first]){
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
                        std::cout << "discover_cure in color "<<  getColorAsString(color) << " is Succeeded\n";
                        b.set_Cure_discovered(color);
                }else if(count < num5){
                        // cout << "count = " << count << "\n";
                        // std::cout << "the amount of cards you have in the color you wanted is less than 5 "<<  getColorAsString(color) << "\n";
                        throw invalid_argument{"ERROR - the amount of cards you have in the color you wanted is less than 5"};
                }  
                return *this;              
                
        }
        Player& Player::treat(const City city){
                if(b.getCure_discovered()[b.getVertex()[city].color] && b[city] > 0 ){
                        // std::cout << b[city] << endl;
                        // std::cout << "treat in city "<<  getCityAsString(city) << " is down to 0, Because a cure has been discovered\n";
                        b.getVertex()[city].disease_level = 0;
                }else if(b.getVertex()[city].disease_level == 0){
                        // std::cout << "treat in city "<<  getCityAsString(city) << " is Fails, Because the disease_level is already 0\n";
                        throw invalid_argument{"ERROR - Attempt to decrease the disease was unsuccessful, because the disease_level is already 0"};
                }else if(city == curr_city && b.getVertex()[city].disease_level > 0) {
                        // std::cout << "treat in city "<<  getCityAsString(city) << " down from " << b.getVertex()[city].disease_level << " to "<< (b.getVertex()[city].disease_level -1)<< " and is Succeeded\n";
                        b.getVertex()[city].disease_level--;
                        // cout << "treat\n";return *this;
                }else{
                        // std::cout << "treat in city "<<  getCityAsString(city) << " Player Cannot treat outside of his current city\n";
                        throw invalid_argument{"ERROR - Player Cannot treat outside of his current city"};
                }
                return *this;
                
        }
        // void Player::setNamePlayer(std::string& namePlayer){
        //         name = namePlayer;
        // }
        std::string Player::role() {
                // cout << "role() base Player\n"; 
                return name; 
        }
        Player& Player::take_card(const City city){ 
                // std::cout << "take_card of city " << getCityAsString(city) << "\n";
                cards[city] = true;
                return *this;
        }
        Player& Player::remove_cards(){
                for(const auto &x : b.getVertex()){
                        cards[x.first] = false;
                }
        return *this;
        }
        bool Player::checkCardByCity(const City city){
                return cards[city];
        }
        City Player::getCurrCity(){
                return curr_city;
        }
        void Player::printAllCards(){
                std::cout << "cards = {";
                int run = 0;
                for(const auto& x: cards){
                        if(x.second){
                                if(run == 0){
                                        cout << getCityAsString(x.first);
                                }
                                else{
                                        cout << ", " << getCityAsString(x.first);

                                }
                                run++;
                             
                        }
                }
                std::cout << "};" << endl;
        }
        Board& Player::getBoard(){
                return b;
        }
        void Player::removeAllCards(){
                for(const auto &x : b.getVertex()){
                        cards[x.first] = false;
                }    
        }

}





//make demo1 && ./demo1 && make demo2 && ./demo2 && make test && ./test && make tidy && make valgrind





