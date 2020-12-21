#include <iostream>
#include "../config/config.h"
#include "../lib/jsoncpp/include/json/json.h"
//#include "config.h"
#include "config_wrapper.h"

int main(int argc, char* argv[])
{
  // ./test_config_json ../../test/data.json
  try{
    // config_wrapper
    set_config_path(argv[1]);
    std::cout << get_num() << std::endl;


    // config
    // config::Config static_config;
    // static_config.load_from_file(argv[1]);
    // double num = static_config.get<double>("get_num");
    // std::cout << num << std::endl;

  }
  catch(std::exception& e){
    std::cout << "You need to add the path to json: ./test_json path_to_json" << std::endl;
  }
  return 0;
}



