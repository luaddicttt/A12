#ifndef DATA_HPP
#define DATA_HPP

#include "json.hpp"
using json=nlohmann::json;

json data;
map<string, int> vertex;

void Init(const char *input);

#endif
