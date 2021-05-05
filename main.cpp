#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>


// using namespace pandemic;
using namespace pandemic;
using namespace std;

const vector<string> cities {"Algiers","Atlanta","Baghdad","Bangkok","Beijing","Bogota","BuenosAires","Cairo","Chennai","Chicago","Delhi","Essen","HoChiMinhCity","HongKong","Istanbul","Jakarta","Johannesburg","Karachi","Khartoum","Kinshasa","Kolkata","Lagos","Lima","London","LosAngeles","Madrid","Manila","MexicoCity","Miami","Milan","Montreal","Moscow","Mumbai","NewYork","Osaka","Paris","Riyadh","SanFrancisco","Santiago","SaoPaulo","Seoul","Shanghai","StPetersburg","Sydney","Taipei","Tehran","Tokyo","Washington"};    // namespace pandemic{

    City getRandomCity() {
        string random = cities[(rand() % cities.size())]; 
		cout << " random = "<< random << "\n";
        return getCityAsObject(random);
    }


int main() {
	// /*
	// * check for color
	// */
	// cout << "0 = "<< getColorAsString(Color::Black) << " == Black \n";
	// cout << "1 = " << getColorAsString(Color::Blue)<< " == Blue \n";
	// cout << "2 = " << getColorAsString(Color::Yellow)<< " == Yellow \n";
	// cout << "3 = " << getColorAsString(Color::Red)<< " == Red \n";
	// // cout << "4 = " << getColorAsString(Color)<< " == Yellow \n\n\n";


	


	// /*
	// * check for city
	// */
	
	// cout << getCityAsString(City::Algiers) << " == Algiers \n";
	// cout << getCityAsString(City::Atlanta) << " == Atlanta \n";
	// cout << getCityAsString(City::Baghdad) << " == Baghdad \n";
	// cout << getCityAsString(City::Bangkok) << " == Bangkok \n";
	// cout << getCityAsString(City::Beijing) << " == Beijing \n";
	// cout << getCityAsString(City::Bogota) << " == Bogota \n";
	// cout << getCityAsString(City::BuenosAires) << " == BuenosAires \n";
	// cout << getCityAsString(City::Cairo) << " == Cairo \n";
	// cout << getCityAsString(City::Chennai) << " == Chennai \n";
	// cout << getCityAsString(City::Chicago) << " == Chicago \n";
	// cout << getCityAsString(City::Delhi) << " == Delhi \n";
	// cout << getCityAsString(City::Essen) << " == Essen \n";
	// cout << getCityAsString(City::HoChiMinhCity) << " == HoChiMinhCity \n";
	// cout << getCityAsString(City::HongKong) << " == HongKong \n";
	// cout << getCityAsString(City::Istanbul) << " == Istanbul \n";
	// cout << getCityAsString(City::Jakarta) << " == Jakarta \n";
	// cout << getCityAsString(City::Johannesburg) << " == Johannesburg \n";
	// cout << getCityAsString(City::Karachi) << " == Karachi \n";
	// cout << getCityAsString(City::Khartoum) << " == Khartoum \n";
	// cout << getCityAsString(City::Kinshasa) << " == Kinshasa \n";
	// cout << getCityAsString(City::Kolkata) << " == Kolkata \n";
	// cout << getCityAsString(City::Lagos) << " == Lagos \n";
	// cout << getCityAsString(City::Lima) << " == Lima \n";
	// cout << getCityAsString(City::London) << " == London \n";
	// cout << getCityAsString(City::LosAngeles) << " == LosAngeles \n";
	// cout << getCityAsString(City::Madrid) << " == Madrid \n";
	// cout << getCityAsString(City::Manila) << " == Manila \n";
	// cout << getCityAsString(City::MexicoCity) << " == MexicoCity \n";
	// cout << getCityAsString(City::Miami) << " == Miami \n";
	// cout << getCityAsString(City::Milan) << " == Milan \n";
	// cout << getCityAsString(City::Montreal) << " == Montreal \n";
	// cout << getCityAsString(City::Moscow) << " == Moscow \n";
	// cout << getCityAsString(City::Mumbai) << " == Mumbai \n";
	// cout << getCityAsString(City::NewYork) << " == NewYork \n";
	// cout << getCityAsString(City::Osaka) << " == Osaka \n";
	// cout << getCityAsString(City::Paris) << " == Paris \n";
	// cout << getCityAsString(City::Riyadh) << " == Riyadh \n";
	// cout << getCityAsString(City::SanFrancisco) << " == SanFrancisco \n";
	// cout << getCityAsString(City::Santiago) << " == Santiago \n";
	// cout << getCityAsString(City::SaoPaulo) << " == SaoPaulo \n";
	// cout << getCityAsString(City::Seoul) << " == Seoul \n";
	// cout << getCityAsString(City::Shanghai) << " == Shanghai \n";
	// cout << getCityAsString(City::StPetersburg) << " == StPetersburg \n";
	// cout << getCityAsString(City::Sydney) << " == Sydney \n";
	// cout << getCityAsString(City::Taipei) << " == Taipei \n";
	// cout << getCityAsString(City::Tehran) << " == Tehran \n";
	// cout << getCityAsString(City::Tokyo) << " == Tokyo \n";
	// cout << getCityAsString(City::Washington) << " == Washington \n";
	// cout << "sdvvsdv";
	Board board;
	// cout << board;

	// board[City::Cairo] = 100;
	// cout << board[City::Cairo] << " == 100 \n";
	// cout << board.is_clean() << " == 0 \n";
	// board[City::Cairo] = 0;
	// cout << board[City::Cairo] << " == 0 \n";
	// cout << board.is_clean() << " == 1 \n";
	
	
	
	// Player p {board,City::Algiers};
	// p.discover_cure(Color::Red);
	// // cout << board;
	// board.remove_cures();
	// // cout << board;
	// bool check_research_station = board.getVertex()[City::Algiers].research_station;
	// p.build();
	// cout << "check_research_station = " << (!check_research_station == board.getVertex()[City::Algiers].research_station);
	// cout << board;  
	cout << "is_connected = "<< board.is_connected(City::Algiers, City::Cairo) << " == 1\n";
	cout << "is_connected = "<< board.is_connected(City::Algiers, City::Istanbul) << " == 1\n";
	cout << "is_connected = "<< board.is_connected(City::Algiers, City::Madrid) << " == 1\n";
	cout << "is_connected = "<< board.is_connected(City::Algiers, City::Paris) << " == 1\n";
	cout << "is_connected = "<< board.is_connected(City::Algiers, City::Washington) << " == 0\n";

	// cout << "const vector<string> cities_in_Black {";
	// int run = 0;
	// for(const auto& x : board.getVertex()){
	// 	if(x.second.color == getColorAsObject("black")){
	// 		if(run == 0){
	// 			cout << "\"" << getCityAsString(x.first) << "\"";
	// 		}else{
	// 			cout << ",\"" << getCityAsString(x.first) << "\"";
	// 			// cout << ", "<< getCityAsString(x.first) ;
	// 		}
	// 		run++;
	// 	}
	// }
	// cout << "};"<< endl;
	


	// cout << "const vector<string> cities_in_Blue {";
	//  run = 0;
	// for(const auto& x : board.getVertex()){
	// 	if(x.second.color == getColorAsObject("Blue")){
	// 		if(run == 0){
	// 			cout << "\"" << getCityAsString(x.first) << "\"";
	// 		}else{
	// 			cout << ",\"" << getCityAsString(x.first) << "\"";
	// 			// cout << ", "<< getCityAsString(x.first) ;
	// 		}
	// 		run++;
	// 	}
	// }
	// cout << "};"<< endl;


	// cout << "const vector<string> cities_in_Red {";
	//  run = 0;
	// for(const auto& x : board.getVertex()){
	// 	if(x.second.color == getColorAsObject("Red")){
	// 		if(run == 0){
	// 			cout << "\"" << getCityAsString(x.first) << "\"";
	// 		}else{
	// 			cout << ",\"" << getCityAsString(x.first) << "\"";
	// 			// cout << ", "<< getCityAsString(x.first) ;
	// 		}
	// 		run++;
	// 	}
	// }
	// cout << "};"<< endl;



	// cout << "const vector<string> cities_in_Yellow {";
	//  run = 0;
	// for(const auto& x : board.getVertex()){
	// 	if(x.second.color == getColorAsObject("Yellow")){
	// 		if(run == 0){
	// 			cout << "\"" << getCityAsString(x.first) << "\"";
	// 		}else{
	// 			cout << ",\"" << getCityAsString(x.first) << "\"";
	// 			// cout << ", "<< getCityAsString(x.first) ;
	// 		}
	// 		run++;
	// 	}
	// }
	// cout << "};"<< endl;
	// cout << getRandomCity();
	// cout << board;
	return 0;
}	

/*
make clean ; make ;clear && clang-9 -c Board.cpp && clang-9 -o run main.cpp Board.o Player.o -lstdc++ && ./run
make clean ; make ;clear && clang-9 -c Board.cpp && clang-9 -o run main.cpp Board.o Player.o -lstdc++ && ./run > OUTPUT2.txt

*/