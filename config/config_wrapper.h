#pragma once
#define STATIC_CONFIG_GETTER(type, key)                                                            \
    type key() { return static_config.get<type>(#key); }

#ifdef __cplusplus
extern "C" {
#endif

void set_config_path(char *file_path);
double get_num();
// void set_config_path(char *file_path);
// int number_of_stations();
// int number_of_end_stations();
// int number_of_robots();
// int number_of_waypoints();
// int waypoint_passing_time();
// int station_passing_time();
// int current_station();
// int current_waypoint();
// int destination();
// double uncertainty();
}
