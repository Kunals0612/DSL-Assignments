#include <iostream>
#include <cstring>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

//SETTING PRECEDENCE
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//CONVERTING INFIX TO POSTFIX
string infixToPostfix(string infix) {
    string postfix = "";
    int stackSize = 0;
    char stackOperators[infix.length()];

    for (char c : infix) {
        if (c == ' ') {
            continue;
        }
        else if (isalnum(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (stackSize > 0 && stackOperators[stackSize - 1] != '(' &&
                   getPrecedence(c) <= getPrecedence(stackOperators[stackSize - 1]))
            {
                postfix += stackOperators[stackSize - 1];
                stackSize--;
            }
            stackOperators[stackSize++] = c;
        }
        else if (c == '(') {
            stackOperators[stackSize++] = c;
        }
        else if (c == ')') {
            while (stackSize > 0 && stackOperators[stackSize - 1] != '(') {
                postfix += stackOperators[stackSize - 1];
                stackSize--;
            }
            if (stackSize > 0 && stackOperators[stackSize - 1] == '(') {
                stackSize--;
            }
        }
    }

    while (stackSize > 0) {
        postfix += stackOperators[stackSize - 1];
        stackSize--;
    }

    return postfix;
}


int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}
