#include<iostream>
#include<functional>
#include<vector>

//#include "config_wrapper.h"

#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "config_wrapper.h"
using namespace std;

// BDD and TDD Development
// TEST_CASE( "Exported functions are computed",  )

TEST_CASE("Testing get_tau method")
{
  REQUIRE(get_tau() == 5.0);
}


TEST_CASE("Testing get_pattern method")
{
  int* my_array;
  cout << endl <<  "Filling the data" << endl;
  get_patterns(my_array); // get_patterns(num,my_array);
  cout << "total size: " << sizeof(my_array) <<endl;
  cout << "individual size: " << sizeof(my_array[0]) <<endl;
  int n = sizeof(my_array) / sizeof(my_array[0]);
  cout << "size: " << n;

  //std::vector<int> a(my_array,my_array+4);
  std::vector<int> b = {1,2,3,4};
  
  for (int i=0;i<4;i++)
  {
    REQUIRE(my_array[i] == b[i]);
  }
}