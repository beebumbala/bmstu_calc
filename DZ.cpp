#include "lab_and_DZ.h"
#include <unordered_map>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <functional>

// float y - заглушка в половине случаев (когда операции унарны)
// y, x стоят наоборот для удобства работы со стеком
std::unordered_map<std::string, std::function<float(float, float)>> lambdas = {
    {"+", [](float x, float y) {return y + x;}},
    {"-", [](float x, float y) {return y - x;}},
    {"*", [](float x, float y) {return y * x;}},
    {"/", [](float x, float y) {return y / x;}},
    {"^", [](float x, float y) {return std::pow(y, x);}},

    {"cos", [](float x, float y) {return std::cos(x);}},
    {"sin", [](float x, float y) {return std::sin(x);}},
    {"tg", [](float x, float y) {return std::tan(x);}},
    {"ctg", [](float x, float y) {return 1 / std::tan(x);}},
    {"exp", [](float x, float y) {return std::exp(x);}},
    {"u-", [](float x, float y) {return -x;}},

};

float solve_from_postfix_form(std::vector<std::string>& splited) {
    if (splited.empty()) return 0;

    std::stack<float> st;

    for (auto& s: splited) {
        if (!priority.count(s)) st.push(std::stof(s));
        else {
            if (priority[s] == 4) {
                float temp = st.top();
                st.pop();
                st.push(lambdas[s](temp, 0));
            }
            else {
                float temp = st.top();
                st.pop();
                temp = lambdas[s](temp, st.top());
                st.pop();
                st.push(temp);
            }
        }
    }
    return st.top();
}
