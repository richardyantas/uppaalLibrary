#pragma once

#define STATIC_CONFIG_GETTER(type, key)                                                            \
    type key() { return static_config.get<type>(#key); }

#ifdef __cplusplus
extern "C" {
#endif

double get_num();

#ifdef __cplusplus
}
#endif

