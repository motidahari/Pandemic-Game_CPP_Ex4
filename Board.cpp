#include "Board.hpp"

using namespace std;

namespace pandemic{

    int& Board::operator[](City city) {
        return Disease_level[city];
    }
    const int Board::operator[](City city) const {return Disease_level.at(city);}
    bool Board::is_clean(){return true;}
    // void Board::remove_cures(){}
    std::ostream& operator<<(std::ostream& os ,const Board& board) {cout << " oper << board\n"; return os;}
}


