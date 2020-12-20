#pragma once
#include <string>
#include <type_traits>
#include <vector>

class Config {
  public:
    Config(){};
    template <typename T>
    T get(const std::string &key);
};