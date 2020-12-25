#pragma once

#define CONFIG_GETTER(type, from, key)                               \
    type key() { load(); return from.get<type>(#key); }  

#define LIST_GETTER(p_type, list_type, from, key)                            \
    void key(p_type* arr)                                            \
    {                                                                \
        load();                                                      \
        auto tmp = from.get<std::vector<list_type>>(#key);           \
        for (int i = 0; i < tmp.size(); i++) { arr[i] = tmp.at(i); } \
    };

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    //void set_config_path(char *file_path);
    double get_tau();
    int get_number_of_patterns();
    void get_patterns(int* patterns);
    //void get_patterns(int32_t num_patterns,int patterns);
#ifdef __cplusplus
}
#endif


// #define STATIC_CONFIG_GETTER(type, key)                                                            \
//    type key() { return static_config.get<type>(#key); }


// #define CONFIG_GETTER(type, json_type, from, key, default)                                         \
//     type key()                                                                                     \
//     {                                                                                              \
//         try {                                                                                      \
//             if (!loaded) {                                                                         \
//                 load();                                                                            \
//             }                                                                                      \
//             return from.get<json_type>(#key);                                             \
//         }                                                                                          \
//         catch (const std::exception &e) {                                                          \
//             log << e.what();                                                                       \
//             return default;                                                                        \
//         }                                                                                          \
//     }


// #define LIST_GETTER(p_type, list_type, from, key)                                                  \
//     void key(int32_t num, p_type* arr)                                                              \
//     {                                                                                              \
//         if (!loaded) {                                                                             \
//             load();                                                                                \
//         }                                                                                          \
//         try {                                                                                \
//             auto tmp = from.get<std::vector<list_type>>(#key);                           \
//             for (int i = 0; i < num; i++) {                                                        \
//                  arr[i] = tmp.at(i);                                                                \
//             }                                                                                      \
//         }                                                                                          \
//         catch (const std::exception &e) {                                                          \
//             log << e.what();                                                                       \
//         }                                                                                          \
//     };
