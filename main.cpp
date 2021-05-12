#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"
#include "sources/Player.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/Medic.hpp"
#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/Virologist.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>


// using namespace pandemic;
using namespace pandemic;
using namespace std;

const vector<string> cities {"Algiers","Atlanta","Baghdad","Bangkok","Beijing","Bogota","BuenosAires","Cairo","Chennai","Chicago","Delhi","Essen","HoChiMinhCity","HongKong","Istanbul","Jakarta","Johannesburg","Karachi","Khartoum","Kinshasa","Kolkata","Lagos","Lima","London","LosAngeles","Madrid","Manila","MexicoCity","Miami","Milan","Montreal","Moscow","Mumbai","NewYork","Osaka","Paris","Riyadh","SanFrancisco","Santiago","SaoPaulo","Seoul","Shanghai","StPetersburg","Sydney","Taipei","Tehran","Tokyo","Washington"};    
const vector<string> color {"Black","Blue","Yellow","Red"};   

    City getRandomCity() {
        string random = cities[(rand() % cities.size())]; 
		// cout << " random = "<< random << "\n";
        return getCityAsObject(random);
    }
	Color getRandomColor() {
        string random = color[(rand() % color.size())]; 
		// cout << " random = "<< random << "\n";
        return getColorAsObject(random);
    }

int main() {

	/*
		check for board
	*/
	Board board;
	// cout << board;
	// // set level to 100 and research_station true
	// for(auto &x : board.getVertex()){
	// 	board[x.first] = 100;	
	// 	x.second.research_station = true;
	// }
	// cout << "board.is_clean = " << ((board.is_clean())? "true": "false") << "\n";

	// //set Cure_discovered true
	// for (auto &x : board.getCure_discovered()){
	// 	x.second = true;
	// }

	// // cout << board << endl;
	// //remove all research_station
	// board.remove_cures();
	// cout << "call to remove_cures()\n";
	// board.remove_stations();
	// cout << "call to remove_stations()\n";
	// //remove all level cure to 0
	// for(auto &x : board.getVertex()){
	// 	board[x.first] = 0;	
	// }

	// cout << "board.is_clean = " << ((board.is_clean())? "true": "false") << "\n";
	// cout << board << endl;

	/*
		check for player
	*/
	// cout << getCityAsString(getRandomCity()) << endl;
	City c = City::Algiers;
	City ni[4] = {
		City::Cairo,
		City::Istanbul,
		City::Madrid,
		City::Paris
	};
	City notNi[4] = {
		City::Chicago,
		City::Miami,
		City::Washington,
		City::Karachi
	};
	// cout << "check drive to ni city\n" ;
	// //check drive to ni city
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	p.drive(ni[i]);
	// }
	// cout << "\ncheck drive to not ni city\n" ;
	// //check drive to not ni city
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	p.drive(notNi[i]);
	// }
	// cout << "\n\n\n" ;

	
	// cout << "check take_card and fly_direct\n";
	// //check take_card and fly_direct
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.take_card(notNi[i]);
	// 	cout << "check the card of the city  => ( "<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	p.fly_direct(notNi[i]);
	// 	cout << "check the card of the city  => ( "<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	cout << "curr city after call to fly_direct =  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;


	// cout << "check take_card and fly_direct with no card of the city\n";
	// //check take_card and fly_direct
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.take_card(notNi[i]);
	// 	cout << "check the card of the city  => ( "<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	p.fly_direct(ni[i]);
	// 	cout << "check the card of the city  => ( "<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	cout << "curr city after call to fly_direct=  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;




		
	// cout << "check take_card and fly_charter\n";
	// //check take_card and fly_charter
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.take_card(notNi[i]);
	// 	cout << "check the card of the city  => ( "<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	p.fly_charter(notNi[i]);
	// 	cout << "check the card of the city  => ( "<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	cout << "curr city after call to fly_charter =  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;


	// cout << "check take_card and fly_charter with no card of the city\n";
	// //check take_card and fly_charter
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.take_card(notNi[i]);
	// 	cout << "check the card of the city  => ("<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	p.fly_charter(ni[i]);
	// 	cout << "check the card of the city  => ("<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	cout << "curr city after call to fly_charter=  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;

	// cout << "Memory address of board = "<< &board << endl;
	//init research station in all the city to true
	// for (int i = 0; i < 48; i++){
	// 	board.getVertex()[getCityAsObject(cities.at(i))].research_station = true;
	// }
	
	// cout << "check take_card and fly_shuttle\n";
	// //check take_card and fly_shuttle
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	// board.getVertex()[p.getCurrCity()].research_station = true;
	// 	// cout << "Memory address of board in for= "<< &p.getBoard() << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	cout <<  "research_station in the city  = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	// p.take_card(notNi[i]);
	// 	// cout << "check the card of the city  => ("<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	p.fly_shuttle(notNi[i]);
	// 	// cout << "check the card of the city  => ("<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	cout << "curr city after call to fly_shuttle =  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;

	// //init research station in all the city to false
	// for (int i = 0; i < 48; i++){
	// 	board.getVertex()[getCityAsObject(cities.at(i))].research_station = false;
	// }
	// cout << "check take_card and fly_shuttle with no card of the city\n";
	// //check take_card and fly_shuttle
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c};
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	// p.take_card(notNi[i]);
	// 	// cout << "check the card of the city  => ("<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	p.fly_shuttle(ni[i]);
	// 	// cout << "check the card of the city  => ("<< getCityAsString(notNi[i]) << ") = " << ((p.checkCardByCity(notNi[i]))? "true": "false") << "\n";
	// 	cout << "curr city after call to fly_shuttle=  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;

	// //init research station in all the city to false
	// for (int i = 0; i < 48; i++){
	// 	board.getVertex()[getCityAsObject(cities.at(i))].research_station = false;
	// }
	// cout << "check take_card and build \n";
	// //check take_card and build 
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c = getRandomCity()};
	// 	board.getVertex()[getRandomCity()].research_station = false;
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.take_card(p.getCurrCity());
	// 	// board.getVertex()[p.getCurrCity()].research_station = true;
	// 	cout << "check the card of the city  => ("<< getCityAsString(p.getCurrCity()) << ") = " << ((p.checkCardByCity(p.getCurrCity()))? "true": "false") << "\n";
	// 	cout <<  "research_station in the city "<< getCityAsString(p.getCurrCity()) << " = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	p.build();
	// 	p.build();
	// 	cout <<  "research_station in the city  = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(p.getCurrCity()) << ") = " << ((p.checkCardByCity(p.getCurrCity()))? "true": "false") << "\n";
	// 	cout << "curr city after call to build =  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "check take_card and build, all the call need to be false\n";
	// //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	Player p {board,c = getRandomCity()};
	// 	board.getVertex()[getRandomCity()].research_station = false;
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	// p.take_card(p.getCurrCity());
	// 	// board.getVertex()[p.getCurrCity()].research_station = true;
	// 	cout << "check the card of the city  => ("<< getCityAsString(p.getCurrCity()) << ") = " << ((p.checkCardByCity(p.getCurrCity()))? "true": "false") << "\n";
	// 	cout <<  "research_station in the city "<< getCityAsString(p.getCurrCity()) << " = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	p.build();
	// 	p.build();
	// 	cout <<  "research_station in the city  = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(p.getCurrCity()) << ") = " << ((p.checkCardByCity(p.getCurrCity()))? "true": "false") << "\n";
	// 	cout << "curr city after call to build =  "<< getCityAsString(p.getCurrCity()) << "\n\n";
	// }
	// cout << "\n\n\n" ;




	// cout << "check discover_cure\n";
	// //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	Player p {board,(c = getRandomCity())};
	// 	board.getVertex()[c].research_station = true;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	Color color = getRandomColor();
	// 	cout << "random color = "<< getColorAsString(color) << endl;
	// 	for (auto &x : board.getVertex()){
	// 		if(x.second.color == color){
	// 			p.take_card(x.first);
	// 		}
	// 	}
	// 	cout <<  "\nresearch_station in the city "<< getCityAsString(p.getCurrCity()) << " = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.discover_cure(color);
	// 	p.discover_cure(color);
	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;


	// cout << "check discover_cure all need to be false\n";
	// //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	Player p {board,(c = getRandomCity())};
	// 	board.getVertex()[c].research_station = true;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	Color color = getRandomColor();
	// 	cout << "random color = "<< getColorAsString(color) << endl;
	// 	cout <<  "\nresearch_station in the city "<< getCityAsString(p.getCurrCity()) << " = " << ((board.getVertex()[p.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	p.discover_cure(color);
	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;
	
	
	
	// cout << "check treet\n";
	// //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	Player p {board,(c = getRandomCity())};
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(p.getCurrCity()) << "\n";
	// 	board[c] = 0;
	// 	p.treat(c);
	// 	board[c] = 100;
	// 	p.treat(c);
	// 	for (auto &x : board.getVertex()){
	// 		if(x.second.color == board.getVertex()[c].color){
	// 			p.take_card(x.first);
	// 		}
	// 	}
	// 	board.getVertex()[c].research_station = true;
	// 	p.discover_cure(board.getVertex()[c].color);
	// 	p.treat(c);
	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;


	// cout << "check role\n";
	// //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	Player p {board,(c = getRandomCity())};
	// 	cout << "role of the Player = "<< p.role() << endl;
	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;


	// /*
	// 	check OperationsExpert
	// */
	// //check the player OperationsExpert
	// for (size_t i = 0; i < 4; i++){
	// 	OperationsExpert OE {board,(c = getRandomCity())};
	// 	cout <<  "curr_city  = " << getCityAsString(OE.getCurrCity()) << "\n";
	// 	board.getVertex()[c].research_station = false;
	// 	cout << "namePlayer = " << OE.role() << endl;
	// 	OE.build();
	// 	cout << "check the card of the city  => ("<< getCityAsString(c) << ") = " << ((OE.checkCardByCity(c))? "true": "false") << "\n";
	// 	cout << "research_station in city "<< (getCityAsString(c)) << " = false\n";
	// 	board.getVertex()[c].research_station = false;
	// 	OE.take_card(c);
	// 	cout << "check the card of the city  => ("<< getCityAsString(c) << ") = " << ((OE.checkCardByCity(c))? "true": "false") << "\n";
	// 	OE.build();
	// 	cout << "check the card of the city after build => ("<< getCityAsString(c) << ") = " << ((OE.checkCardByCity(c))? "true": "false") << "\n";
	// 	OE.build();
	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;


	// /*
	// 	check Dispatcher
	// */
	// //check the player Dispatcher
	// for (size_t i = 0; i < 4; i++){
	// 	Dispatcher dis {board,(c = getRandomCity())};
	// 	City c2 = getRandomCity();
	// 	cout << "namePlayer = " << dis.role() << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(dis.getCurrCity()) << "\n";
	// 	cout <<  "random City For Fly  = " << getCityAsString(c2) << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(c2) << ") = " << ((dis.checkCardByCity(c2))? "true": "false") << "\n";

	// 	board.getVertex()[c].research_station = true;
	// 	cout << "research_station in city "<< (getCityAsString(c)) << " = "<< ((board.getVertex()[c].research_station)?"true":"false") <<"\n";
	// 	dis.take_card(c2);
	// 	dis.fly_direct(c2);
	// 	cout <<  "curr_city  = " << getCityAsString(dis.getCurrCity()) << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(c2) << ") = " << ((dis.checkCardByCity(c2))? "true": "false") << "\n\n";
		
	// 	board.getVertex()[c2].research_station = true;
	// 	cout << "research_station in city "<< (getCityAsString(c2)) << " = "<< ((board.getVertex()[c2].research_station)?"true":"false") <<"\n";
	// 	c2 = getRandomCity();
	// 	cout <<  "random City For Fly  = " << getCityAsString(c2) << "\n";
	// 	dis.fly_direct(c2);
	// 	cout <<  "curr_city  = " << getCityAsString(dis.getCurrCity()) << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(c2) << ") = " << ((dis.checkCardByCity(c2))? "true": "false") << "\n\n";
	
	// 	board.getVertex()[c2].research_station = false;
	// 	cout << "research_station in city "<< (getCityAsString(c2)) << " = "<< ((board.getVertex()[c2].research_station)?"true":"false") <<"\n";
	// 	c2 = getRandomCity();
	// 	cout <<  "random City For Fly  = " << getCityAsString(c2) << "\n";
	// 	dis.take_card(c2);
	// 	dis.fly_direct(c2);
	// 	cout <<  "curr_city  = " << getCityAsString(dis.getCurrCity()) << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(c2) << ") = " << ((dis.checkCardByCity(c2))? "true": "false") << "\n";

	// 	board.getVertex()[c2].research_station = false;
	// 	cout << "research_station in city "<< (getCityAsString(c2)) << " = "<< ((board.getVertex()[c2].research_station)?"true":"false") <<"\n";
	// 	c2 = getRandomCity();
	// 	cout <<  "random City For Fly  = " << getCityAsString(c2) << "\n";
	// 	dis.fly_direct(c2);
	// 	cout <<  "curr_city  = " << getCityAsString(dis.getCurrCity()) << "\n";
	// 	cout << "check the card of the city  => ("<< getCityAsString(c2) << ") = " << ((dis.checkCardByCity(c2))? "true": "false") << "\n\n";
	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;




	// /*
	// 	check Scientist
	// */
	// //check the player Scientist
	// cout << "check player Scientist\n";
	// cout << "namePlayer = " << dis.role() << endl;
	// check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	Scientist Sci {board,(c = getRandomCity()),2};
	// 	board.getVertex()[c].research_station = true;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(Sci.getCurrCity()) << "\n";
	// 	Color color = getRandomColor();
	// 	cout << "random color = "<< getColorAsString(color) << endl;
	// 	for (auto &x : board.getVertex()){
	// 		if(x.second.color == color){
	// 			Sci.take_card(x.first);
	// 		}
	// 	}
	// 	cout <<  "\nresearch_station in the city "<< getCityAsString(Sci.getCurrCity()) << " = " << ((board.getVertex()[Sci.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout <<  "curr_city  = " << getCityAsString(Sci.getCurrCity()) << "\n";
	// 	Sci.discover_cure(color);
	// 	Sci.discover_cure(color);

	// 	board.remove_cures();
	// 	Sci.removeAllCards();
	// 	board.getVertex()[Sci.getCurrCity()].research_station = true;
	// 	Sci.discover_cure(color);

	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;



	// /*
	// 	check Researcher
	// */
	// //check the player Researcher
	// cout << "check player Researcher\n";
	// //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	Researcher Res {board,(c = getRandomCity())};
	// 	cout << "namePlayer = " << Res.role() << endl;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(Res.getCurrCity()) << "\n";
	// 	Color color = getRandomColor();
	// 	cout << "random color = "<< getColorAsString(color) << endl;
	// 	for (auto &x : board.getVertex()){
	// 		if(x.second.color == color){
	// 			Res.take_card(x.first);
	// 		}
	// 	}
	// 	cout <<  "\nresearch_station in the city "<< getCityAsString(Res.getCurrCity()) << " = " << ((board.getVertex()[Res.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout <<  "curr_city  = " << getCityAsString(Res.getCurrCity()) << "\n";
	// 	Res.discover_cure(color);
	// 	Res.discover_cure(color);

	// 	board.remove_cures();
	// 	Res.removeAllCards();
	// 	Res.discover_cure(color);

	// 	cout << "\n\n";
	// }
	// cout << "\n\n\n" ;




	// /*
	// 	check Medic
	// */
	// //check the player Medic
	// cout << "check player Medic\n";
	// //check take_card and build without take a card
	
	// for (size_t i = 0; i < 4; i++){
	// 	Medic Med {board,(c = getRandomCity())};
	// 	cout << "namePlayer = " << Med.role() << endl;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(Med.getCurrCity()) << "\n";

	// 	for (auto &x : board.getVertex()){
	// 		board[x.first] = 100;
	// 	}
	// 	for (auto &x : board.getCure_discovered()){
	// 		x.second = true;
	// 	}
		
	// 	for (size_t i = 0; i < 4; i++){
	// 		if(board.is_connected(c = getRandomCity(), Med.getCurrCity())){
	// 			Med.drive(c);
	// 		}
	// 		cout <<  "curr_city  = " << getCityAsString(Med.getCurrCity()) << "\n";
	// 		cout <<  "random city  = " << getCityAsString(c) << "\n";
	// 		Med.take_card(Med.getCurrCity());
	// 		cout << "check the card of the city  => ("<< getCityAsString(Med.getCurrCity()) << ") = " << ((Med.checkCardByCity(Med.getCurrCity()))? "true": "false") << "\n";
	// 		Med.fly_charter(c);

	// 		// Med.take_card(c);
	// 		board.getVertex()[Med.getCurrCity()].research_station = true;
	// 		board.getVertex()[c = getRandomCity()].research_station = true;
	// 		Med.fly_shuttle(c);

	// 		Med.take_card(c = getRandomCity());
	// 		cout << "check the card of the city  => ("<< getCityAsString(c) << ") = " << ((Med.checkCardByCity(c))? "true": "false") << "\n";
	// 		Med.fly_direct(c);
	// 		cout << "\n\n";
	// 	}
	// 	cout << "\n\n\n" ;
	// 	cout << "check move to city all neet to be false = " << endl;
	// 	for (size_t i = 0; i < 4; i++){
	// 		if(!board.is_connected(c = getRandomCity(), Med.getCurrCity())){
	// 			Med.drive(c);
	// 		}
	// 		cout <<  "curr_city  = " << getCityAsString(Med.getCurrCity()) << "\n";
	// 		cout <<  "random city  = " << getCityAsString(c) << "\n";
	// 		// Med.take_card(Med.getCurrCity());
	// 		cout << "check the card of the city  => ("<< getCityAsString(Med.getCurrCity()) << ") = " << ((Med.checkCardByCity(Med.getCurrCity()))? "true": "false") << "\n";
	// 		Med.fly_charter(c);

	// 		// Med.take_card(c);
	// 		board.getVertex()[Med.getCurrCity()].research_station = false;
	// 		board.getVertex()[c = getRandomCity()].research_station = false;
	// 		Med.fly_shuttle(c);

	// 		// Med.take_card(c = getRandomCity());
	// 		cout << "check the card of the city  => ("<< getCityAsString(c) << ") = " << ((Med.checkCardByCity(c))? "true": "false") << "\n";
	// 		Med.fly_direct(c);
	// 		cout << "\n\n";
	// 	}
	// }
	// cout << "\n\n\n" ;



	// /*
	// 	check Virologist
	// */
	// //check the player Virologist
	// cout << "check player Virologist\n";
	// for (size_t i = 0; i < cities.size(); i++){
	// 	Virologist Vir {board,(c = getRandomCity())};
	// 	cout << "namePlayer = " << Vir.role() << endl;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	cout <<  "curr_city  = " << getCityAsString(Vir.getCurrCity()) << "\n";	
	// 	board[getCityAsObject(cities.at(i))] = 100;
	// 	cout << "disease_level in city " << cities.at(i) << " = " << board[getCityAsObject(cities.at(i))]<< endl;
	// 	Vir.take_card(getCityAsObject(cities.at(i)));
	// 	cout << "check the card of the city  => ("<< cities.at(i) << ") = " << ((Vir.checkCardByCity(getCityAsObject(cities.at(i))))? "true": "false") << "\n";
	// 	Vir.treat(getCityAsObject(cities.at(i)));
	// 	cout << "check the card of the city  => ("<< cities.at(i) << ") = " << ((Vir.checkCardByCity(getCityAsObject(cities.at(i))))? "true": "false") << "\n\n";	
	// }

	// /*
	// 	check GeneSplicer
	// */
	// cout << "check discover_cure in GeneSplicer\n";
	// // //check take_card and build without take a card
	// for (size_t i = 0; i < 4; i++){
	// 	board.remove_cures();
	// 	GeneSplicer Gen {board,(c = getRandomCity())};
	// 	board.getVertex()[c].research_station = true;
	// 	cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
	// 	Color color = getRandomColor();
	// 	cout << "random color = "<< getColorAsString(color) << endl;
	// 	for (size_t i = 0; i < 5; i++){
	// 		c = getRandomCity();
	// 		cout << "the color of the city is: " << getColorAsString(board.getVertex()[c].color) << endl;
	// 		Gen.take_card(c);
	// 	}
	// 	cout <<  "\nresearch_station in the city "<< getCityAsString(Gen.getCurrCity()) << " = " << ((board.getVertex()[Gen.getCurrCity()].research_station)? "true" : "false") << "\n";
	// 	cout <<  "curr_city  = " << getCityAsString(Gen.getCurrCity()) << "\n";
	// 	Gen.discover_cure(color);
	// 	cout << "\n\n" ;
	// }
	// cout << "\n\n\n" ;



	/*
		check FieldDoctor
	*/
	cout << "check  FieldDoctor\n";
	// //check take_card and build without take a card
	for (size_t i = 0; i < 4; i++){
		FieldDoctor Fie {board,(c = getRandomCity())};
		board[c] = 100;
		board.getCure_discovered()[board.getVertex()[c].color] = false;
		cout << "namePlayer = " << Fie.role() << endl;
		cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
		for(auto &x : board.getVertex()){
			board[x.first] = 100;
			cout << "board[" << getCityAsString(x.first)<< "] = " << board[x.first] << endl ; 
			Fie.treat(x.first);
			cout << "board[" << getCityAsString(x.first)<< "] = " << board[x.first] << endl ; 
			for (auto &x1 : board.getVertex()){
				if(x1.second.color == board.getVertex()[c].color){
					Fie.take_card(x1.first);
				}
			}
			board.getVertex()[c].research_station = true;
			Fie.treat(x.first);
			Fie.discover_cure(board.getVertex()[c].color);
			Fie.treat(x.first);
			cout << "board[" << getCityAsString(x.first)<< "] = " << board[x.first] << endl ; 
			cout << "\n";
		}
		// board.getVertex()[c].research_station = true;
		// cout << "color of the city = "<< getColorAsString(board.getVertex()[c].color) << endl;
		// Color color = getRandomColor();
		// cout << "random color = "<< getColorAsString(color) << endl;
		// for (size_t i = 0; i < 5; i++){
		// 	c = getRandomCity();
		// 	cout << "the color of the city is: " << getColorAsString(board.getVertex()[c].color) << endl;
		// 	Fie.take_card(c);
		// }
		// cout <<  "\nresearch_station in the city "<< getCityAsString(Fie.getCurrCity()) << " = " << ((board.getVertex()[Fie.getCurrCity()].research_station)? "true" : "false") << "\n";
		// cout <<  "curr_city  = " << getCityAsString(Fie.getCurrCity()) << "\n";
		// Fie.discover_cure(color);
		cout << "\n\n" ;

	}
	cout << "\n\n\n" ;


	return 0;
}

// int main() {
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
	// Board board;
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
	// cout << "is_connected = "<< board.is_connected(City::Algiers, City::Cairo) << " == 1\n";
	// cout << "is_connected = "<< board.is_connected(City::Algiers, City::Istanbul) << " == 1\n";
	// cout << "is_connected = "<< board.is_connected(City::Algiers, City::Madrid) << " == 1\n";
	// cout << "is_connected = "<< board.is_connected(City::Algiers, City::Paris) << " == 1\n";
	// cout << "is_connected = "<< board.is_connected(City::Algiers, City::Washington) << " == 0\n";

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
// 	return 0;
// }	

/*objects/City.o objects/Color.o
make clean;  make; clear; clang++-9 -std=c++2a -o main main.cpp objects/Player.o objects/Board.o objects/OperationsExpert.o  objects/Dispatcher.o objects/FieldDoctor.o objects/GeneSplicer.o objects/Medic.o objects/Researcher.o objects/Scientist.o objects/Virologist.o && ./main
make clean;  make; clear; clang++-9 -std=c++2a -o main main.cpp objects/Player.o objects/Board.o objects/OperationsExpert.o  objects/Dispatcher.o objects/FieldDoctor.o objects/GeneSplicer.o objects/Medic.o objects/Researcher.o objects/Scientist.o objects/Virologist.o && ./main > OUTPUT.txt
make clean ; clear; make ; clang-9 -c Board.cpp && clang-9 -o run main.cpp Board.o Player.o -lstdc++ && ./run
make clean ; make ;clear && clang-9 -c Board.cpp && clang-9 -o run main.cpp Board.o Player.o -lstdc++ && ./run > OUTPUT2.txt

*/