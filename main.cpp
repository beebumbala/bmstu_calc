#include "lab_and_DZ.h"

#include <iostream>
#include <vector>

static std::vector<std::string> split(const std::string& input, char sep = ' ');


int main() {
    std::string input;
    std::cout << "Enter your math problem: ";
    std::getline(std::cin, input);

    std::string result = transform_to_postfix(input);
    std::cout << "Postfix form: " << result << std::endl;
    std::vector<std::string> splited = split(result);

    for (size_t i = 0; i < splited.size(); ++i) {
        if (splited[i] == "x") {
            std::cout << "Enter x value: ";
            std::cin >> input;
            splited[i] = input;
        }
    }
    try {
        float res = solve_from_postfix_form(splited);
        std::cout << "Problem result is: " << res << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error occured, details: " << e.what() << std::endl;
    }
    return 0;
}


static std::vector<std::string> split(const std::string& input, const char sep) {
    std::vector<std::string> res;
    std::string current;
    for (const auto i: input) {
        if (i == sep) {
            res.push_back(current);
            current.clear();
        }
        else {
            current += i;
        }
    }
    if (!current.empty()) {
        res.push_back(current);
    }
    return res;
}