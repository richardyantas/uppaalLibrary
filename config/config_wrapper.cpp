#include <iostream>
#include <limits>
#include <string>
#include "config_wrapper.h"
#include "config.h"
#include "log.h"

Log log{"libconfig.log"};

config::Config static_config;
//config::Config dynamic_config;
bool loaded = false;

void load(){
    if(loaded)
    {
        return;
    }
    static_config.load_from_file("/home/serendipita/Documents/uppaalLibrary/config/static_json.json");
    loaded = true;
}

CONFIG_GETTER(double, static_config, get_tau)
LIST_GETTER(int, int, static_config, get_patterns)

// std::string get_name(std::string name)
// {
//     int name_length = name.size();
//     std::string new_name = name.substr(3,name_length-4);
//     return new_name;
// }

// CONFIG_GETTER(double, double, static_config, get_tau, 0)
// CONFIG_GETTER(int, int, static_config, get_number_of_patterns, 0)
// LIST_GETTER(int, int, dynamic_config, get_patterns);
