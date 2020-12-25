// #include "config.h"

// template <>
// double Config::get<double>(const std::string &key)
// {
//   return 5.0;// json[key]
// }


#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "config.h"

template <>
std::vector<int> config::convert_from_json<std::vector<int>>(const Json::Value &value)
{
    if (value.type() != Json::ValueType::arrayValue) {
        throw config::InvalidValueException();
    }

    std::vector<int> result;

    for (auto itr = value.begin(); itr != value.end(); itr++) {
        result.push_back(value[itr.index()].asInt());
    }

    return result;
}

config::Config::Config(const std::string &file_path)
{
    load_from_file(file_path);
}

void config::Config::load_from_file(const std::string &file_path)
{
    std::ifstream config_file(file_path);
    config_file >> json;
}

void config::Config::write_to_file(const std::string &file_path)
{
    std::ofstream config_file(file_path);
    config_file << json;
}

template <>
int config::Config::get<int>(const std::string &key)
{
    if (!json.isMember(key)) {
        throw config::InvalidKeyException(key);
    };

    return json[key].asInt();
}

template <>
std::string config::Config::get<std::string>(const std::string &key)
{
    if (!json.isMember(key)) {
        throw config::InvalidKeyException(key);
    };

    return json[key].asString();
}

template <>
double config::Config::get<double>(const std::string &key)
{
    if (!json.isMember(key)) {
        throw config::InvalidKeyException(key);
    };

    return json[key].asDouble();
}

template <>
std::vector<int> config::Config::get<std::vector<int>>(const std::string &key)
{
    if (!json.isMember(key)) {
        throw config::InvalidKeyException(key);
    }

    if (json[key].type() != Json::ValueType::arrayValue) {
        throw config::InvalidValueException();
    }

    return config::convert_from_json<std::vector<int>>(json[key]);
}

template <>
std::map<int, std::vector<int>>
config::Config::get<std::map<int, std::vector<int>>>(const std::string &key)
{
    if (!json.isMember(key)) {
        throw config::InvalidKeyException(key);
    }

    if (json[key].type() != Json::ValueType::objectValue) {
        throw config::InvalidValueException();
    }

    std::map<int, std::vector<int>> result;

    for (auto itr = json[key].begin(); itr != json[key].end(); itr++) {
        std::vector<int> value = config::convert_from_json<std::vector<int>>(json[key][itr.name()]);
        result.insert({itr.key().asInt(), value});
    }

    return result;
}
