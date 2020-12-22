#pragma once
//#define STATIC_CONFIG_GETTER(type, key)                                                            \
//    type key() { return static_config.get<type>(#key); }

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    //void set_config_path(char *file_path);
    double get_tau();
    int get_number_of_patterns();
    void get_patterns(int32_t num_patterns,int patterns);
}
