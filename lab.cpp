#include "lab_and_DZ.h"
#include <unordered_map>
#include <stack>
#include <string>


std::string transform_to_postfix(const std::string& inp) {
    std::string res;
    std::stack<std::string> operations;
    for (int i = 0; i < inp.length(); ++i) {
        char c = inp[i];

        if (std::isalpha(c)) {
            std::string temp;
            while (std::isalpha(c) && i < inp.length()) {
                temp += c;
                c = inp[++i];
            }
            --i;
            if (priority.count(temp)) {
                operations.push(temp);
            }
            else {
                res += temp + ' ';
            }
        }
        else if (std::isdigit(c)) {
            while ((std::isdigit(c) || c == '.' || c == ',') && i < inp.length()) {
                res += c;
                c = inp[++i];
            }
            res += ' ';
            --i;
        }
        else if (c == '(') {
            operations.push("(");
        }
        else if (c == ')') {
            while (!operations.empty() && operations.top() != "(") {
                res += operations.top() + " ";
                operations.pop();
            }
            if (!operations.empty()) {
                operations.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            std::string operation;
            if (c == '-' && (i == 0 || inp[i-1] == '(' || priority.count(std::string(1, inp[i-1])))) {
                operation = "u-";
            }
            else {
                operation = std::string(1, c);
            }

            while (!operations.empty() && priority[operations.top()] >= priority[operation] && operations.top() != "(") {
                res += operations.top() + " ";
                operations.pop();
            }
            operations.push(operation);
        }
    }
    while (!operations.empty()) {
        res += operations.top() + ' ';
        operations.pop();
    }
    return res;
}