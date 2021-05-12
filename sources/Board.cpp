#include "Board.hpp"
using namespace std ;


namespace pandemic {
    Board::Board(){
        std::ifstream cities_file{"cities_map.txt"};
        initColor();
        initGraph(cities_file);
    }
    int& Board::operator[](City city) {
        return vertex[city].disease_level;
    }
    void Board::initColor(){
        Cure_discovered[getColorAsObject("Black")] = false;
        Cure_discovered[getColorAsObject("Blue")] = false;
        Cure_discovered[getColorAsObject("Red")] = false;
        Cure_discovered[getColorAsObject("Yellow")] = false;
    }
    void Board::initGraph(std::ifstream& cities_file){
        std::string line;
        std::string delimiter = " ";
        size_t pos = 0;
        std::string word;
        std::string city;
        while(std::getline(cities_file, line)){
            int run = 0;
            int length = line.length();
            while ((pos = line.find(delimiter)) != std::string::npos) {
                word = line.substr(0, pos);
                line.erase(0, pos + delimiter.length());
                if(run == 0){
                    city = word;
                    vertex[getCityAsObject(word)];
                    // Cure_discovered[getCityAsObject(word)] = false;
                    vertex[getCityAsObject(word)].disease_level = 0;
                    vertex[getCityAsObject(word)].research_station = false;
                }else if(run == 1){
                    vertex[getCityAsObject(city)].color = getColorAsObject(word); 
                }else if(run > 1){
                    vertex[getCityAsObject(city)].neighbors.insert(getCityAsObject(word));
                }
                run++;
            }
            if(length > 0){
                vertex[getCityAsObject(city)].neighbors.insert(getCityAsObject(line));
            }
        }
        // printCure_discovered();
        // printMap();
    }
    void Board::printCure_discovered(){
        for (const auto &i : Cure_discovered) {
            std::cout <<"Cure_discovered["<< getColorAsString(i.first) << "] = " << i.second << "\n";
        }
        cout << "\n";
    }
    void Board::printMap(){
        std::set<City>::iterator it;
        for (const auto &i : vertex) {
            // std::cout <<"mat["<< getCityAsString(i.first) << "] = {\n\tcolor = "<< getColorAsString(i.second.color) <<", \n\tdisease_level = "<< i.second.disease_level << ", \n\tresearch_station = "<< ((i.second.research_station == 0)? "false" : "true" )<< ", \n\tni{";
            // std::cout <<"mat["<< i.first << "] = {color = "<< getColorAsString(i.second.color) <<", ni[";
            std::string ni;
            int run = 0;
            for (it=vertex[i.first].neighbors.begin(); it!=vertex[i.first].neighbors.end(); ++it){
                if(run == 0){
                    std::cout << getCityAsString(*it);
                }else{
                    std::cout << ", " << getCityAsString(*it);
                }
                run++;
            }
            std::cout <<"}" << "\n}\n";
        }
    }
    bool Board::is_clean() {
        for(auto &x : vertex){
            if(x.second.disease_level > 0) {
                return false;
            }
        }
        return true;
    }
    std::ostream& operator<<(std::ostream& os,const Board& b) {
        std::string str;
        std::set<City>::iterator it;
        for (const auto &i : b.vertex) {
            // str += "mat["<< getCityAsString(i.first) +  "] = {\n\tcolor = " + getColorAsString(i.second.color) + ", \n\tdisease_level = " +  i.second.disease_level + ", \n\tresearch_station = " + ((i.second.research_station == 0)? "false" : "true" )<< ", \n\tni{";
            os <<"mat["<< getCityAsString(i.first) << "] = {\n\tcolor = "<< getColorAsString(i.second.color) <<", \n\tdisease_level = "<< i.second.disease_level << ", \n\tresearch_station = "<< ((!i.second.research_station)? "false" : "true" )<< ", \n\tni{";
            // std::cout <<"mat["<< i.first << "] = {color = "<< getColorAsString(i.second.color) <<", ni[";
            std::string ni;
            int run = 0;
            for (it=b.vertex.at(i.first).neighbors.begin(); it!=b.vertex.at(i.first).neighbors.end(); ++it){
                if(run == 0){
                    os << getCityAsString(*it);
                }else{
                    os << ", " << getCityAsString(*it);
                }
                run++;
            }
            os <<"}" << "\n}\n";
        }
        for (const auto &i : b.Cure_discovered) {
            os <<"Cure_discovered["<< getColorAsString(i.first) << "] = " << i.second << "\n";
        }
        return os;
    }
    bool Board::is_connected(const City city1, const City city2){
        // return (vertex.at(city1).neighbors.find(city2) != (vertex.at(city1).neighbors.end()) && (vertex.at(city2).neighbors.find(city1) != vertex.at(city2).neighbors.end()));
        return vertex[city1].neighbors.count(city2) > 0 && vertex[city2].neighbors.count(city1) > 0;

    }
    void Board::set_Cure_discovered(const Color color){
        Cure_discovered[color] = true;
    }
    void Board::remove_cures(){
        for (auto &i : Cure_discovered) {
            i.second = false;
        }
    }
    void Board::remove_stations(){
        for (auto &i : vertex) {
            i.second.research_station = false;
        }
    }
    bool Board::is_cure(const City city){
        return Cure_discovered[vertex[city].color];
    }
    std::map<City, Node>& Board::getVertex(){
        return this->vertex;
    }
    std::map<Color, bool>& Board::getCure_discovered(){
        return this->Cure_discovered;
    }
    
}