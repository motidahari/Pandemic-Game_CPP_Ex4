/**
  * Number With Units Tests
  * Create a Number With Units
  * CPP course, Ariel University
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */

#include <string>
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>

// using namespace pandemic;
using namespace std;




/**
 * Test for the operator -
 */
TEST_CASE("test for the operator -"){
    for(int i = 0; i < 5000; i++){
      CHECK_EQ(1,1);
    }
}



/*
make demo1 && ./demo1
make demo2 && ./demo2
make test && ./test

make tidy
make valgrind
*/