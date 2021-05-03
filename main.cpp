

#include "Color.hpp"
#include "City.hpp"
#include <iostream>

// using namespace pandemic;
using namespace std;

int main() {
	/*
	* check for color
	*/
	cout << "0 = "<< getColorAsString(0) << " == Black \n";
	cout << "1 = " << getColorAsString(1)<< " == Blue \n";
	cout << "2 = " << getColorAsString(2)<< " == Red \n";
	cout << "3 = " << getColorAsString(3)<< " == Yellow \n";
	cout << "4 = " << getColorAsString(4)<< " == Yellow \n\n\n";


	


	/*
	* check for city
	*/
	
	cout << getCityAsString(City::Algiers) << " == Algiers \n";
	cout << getCityAsString(City::Atlanta) << " == Atlanta \n";
	cout << getCityAsString(City::Baghdad) << " == Baghdad \n";
	cout << getCityAsString(City::Bangkok) << " == Bangkok \n";
	cout << getCityAsString(City::Beijing) << " == Beijing \n";
	cout << getCityAsString(City::Bogota) << " == Bogota \n";
	cout << getCityAsString(City::BuenosAires) << " == BuenosAires \n";
	cout << getCityAsString(City::Cairo) << " == Cairo \n";
	cout << getCityAsString(City::Chennai) << " == Chennai \n";
	cout << getCityAsString(City::Chicago) << " == Chicago \n";
	cout << getCityAsString(City::Delhi) << " == Delhi \n";
	cout << getCityAsString(City::Essen) << " == Essen \n";
	cout << getCityAsString(City::HoChiMinhCity) << " == HoChiMinhCity \n";
	cout << getCityAsString(City::HongKong) << " == HongKong \n";
	cout << getCityAsString(City::Istanbul) << " == Istanbul \n";
	cout << getCityAsString(City::Jakarta) << " == Jakarta \n";
	cout << getCityAsString(City::Johannesburg) << " == Johannesburg \n";
	cout << getCityAsString(City::Karachi) << " == Karachi \n";
	cout << getCityAsString(City::Khartoum) << " == Khartoum \n";
	cout << getCityAsString(City::Kinshasa) << " == Kinshasa \n";
	cout << getCityAsString(City::Kolkata) << " == Kolkata \n";
	cout << getCityAsString(City::Lagos) << " == Lagos \n";
	cout << getCityAsString(City::Lima) << " == Lima \n";
	cout << getCityAsString(City::London) << " == London \n";
	cout << getCityAsString(City::LosAngeles) << " == LosAngeles \n";
	cout << getCityAsString(City::Madrid) << " == Madrid \n";
	cout << getCityAsString(City::Manila) << " == Manila \n";
	cout << getCityAsString(City::MexicoCity) << " == MexicoCity \n";
	cout << getCityAsString(City::Miami) << " == Miami \n";
	cout << getCityAsString(City::Milan) << " == Milan \n";
	cout << getCityAsString(City::Montreal) << " == Montreal \n";
	cout << getCityAsString(City::Moscow) << " == Moscow \n";
	cout << getCityAsString(City::Mumbai) << " == Mumbai \n";
	cout << getCityAsString(City::NewYork) << " == NewYork \n";
	cout << getCityAsString(City::Osaka) << " == Osaka \n";
	cout << getCityAsString(City::Paris) << " == Paris \n";
	cout << getCityAsString(City::Riyadh) << " == Riyadh \n";
	cout << getCityAsString(City::SanFrancisco) << " == SanFrancisco \n";
	cout << getCityAsString(City::Santiago) << " == Santiago \n";
	cout << getCityAsString(City::SaoPaulo) << " == SaoPaulo \n";
	cout << getCityAsString(City::Seoul) << " == Seoul \n";
	cout << getCityAsString(City::Shanghai) << " == Shanghai \n";
	cout << getCityAsString(City::StPetersburg) << " == StPetersburg \n";
	cout << getCityAsString(City::Sydney) << " == Sydney \n";
	cout << getCityAsString(City::Taipei) << " == Taipei \n";
	cout << getCityAsString(City::Tehran) << " == Tehran \n";
	cout << getCityAsString(City::Tokyo) << " == Tokyo \n";
	cout << getCityAsString(City::Washington) << " == Washington \n";


	return 0;
}	

/*
clear && clang-9 -o run main.cpp -lstdc++ && ./run
*/