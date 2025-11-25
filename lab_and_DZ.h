#pragma once

#include <unordered_map>
#include <string>
#include <vector>

inline std::unordered_map<std::string, int> priority = {
    {"+", 1}, {"-", 1},
    {"*", 2}, {"/", 2},
    {"^", 3},
    {"cos", 4}, {"sin", 4}, {"tg", 4}, {"ctg", 4}, {"exp", 4}, {"u-", 4}
};

// Laba
std::string transform_to_postfix(const std::string& inp);

// DZ
float solve_from_postfix_form(std::vector<std::string>& postfix);