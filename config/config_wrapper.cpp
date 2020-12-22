#define STATIC_CONFIG_GETTER(type, key)                                                            \
   type key() { return static_config.get<type>(#key); }


#define CONFIG_GETTER(type, json_type, from, key, default)                                         \
    type key()                                                                                     \
    {                                                                                              \
        try {                                                                                      \
            if (!loaded) {                                                                         \
                load();                                                                            \
            }                                                                                      \
            return from.get<json_type>(#key);                                             \
        }                                                                                          \
        catch (const std::exception &e) {                                                          \
            log << e.what();                                                                       \
            return default;                                                                        \
        }                                                                                          \
    }


#define LIST_GETTER(p_type, list_type, from, key)                                                  \
    void key(int32_t num, p_type* arr)                                                              \
    {                                                                                              \
        if (!loaded) {                                                                             \
            load();                                                                                \
        }                                                                                          \
        try {                                                                                      \
            auto tmp = from.get<std::vector<list_type>>(#key);                           \
            for (int i = 0; i < num; i++) {                                                        \
                arr[i] = tmp.at(i);                                                                \
            }                                                                                      \
        }                                                                                          \
        catch (const std::exception &e) {                                                          \
            log << e.what();                                                                       \
        }                                                                                          \
    };


#include <iostream>
#include <limits>
#include <string>
#include "config_wrapper.h"
#include "config.h"
#include "log.h"

Log log{"libconfig.log"};

config::Config static_config;
config::Config dynamic_config;

bool loaded = false;

void load(){
    if(loaded)
    {
        return;
    }
    static_config.load_from_file("static_config.json");
    //dynamic_config.load_from_file("dynamic_config.json");
    loaded = true;
}

std::string get_name(std::string name)
{
    int name_length = name.size();
    std::string new_name = name.substr(3,name_length-4);
    return new_name;
}

CONFIG_GETTER(double, double, static_config, get_tau, 0)
CONFIG_GETTER(int, int, static_config, get_number_of_patterns, 0)
// LIST_GETTER(int, int, dynamic_config, get_patterns);

