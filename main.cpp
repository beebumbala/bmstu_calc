#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>


std::unordered_map<std::string, int> priority = {
    {"+", 1}, {"-", 1},
    {"*", 2}, {"/", 2},
    {"^", 3},
    {"cos", 4}, {"sin", 4}, {"tg", 4}, {"ctg", 4}, {"exp", 4}, {"u-", 4}
};


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

int main() {
    std::string input;
    std::cout << "Enter your math problem: ";
    std::getline(std::cin, input);

    const std::string result = transform_to_postfix(input);
    std::cout << "Postfix form: " << result << std::endl;

    return 0;
}
