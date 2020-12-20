#include "config.h"

template <>
double Config::get<double>(const std::string &key)
{
  return 5.0;// json[key]
}

