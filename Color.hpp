#pragma once
#include <iostream>

enum Color{
    Black,
    Blue,
    Red,
    Yellow
};

inline std::string getColorAsString(Color num) {
    return (num == 0) ? "Black": (num == 1) ? "Blue": (num == 2) ? "Red": "Yellow";
}