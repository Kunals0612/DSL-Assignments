#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[101];
    int index;

public:
    Stack() {
        for (int i = 0; i < 101; i++) {
            arr[i] = ' '; // Initialize the stack with spaces
        }
        index = -1;
    }
 
    bool empty() {
        return (index == -1);
    }

    bool full() {
        return (index == 100);
    }

    void push(char ch) {
        if (!full()) {
            index++;
            arr[index] = ch;
        }
    }

    char pop() {
        if (!empty()) {
            char top = arr[index];
            arr[index] = ' '; // Clear the element
            index--;
            return top;
        }
        return ' '; // Return space for empty stack
    }
};

bool isValidParenthesis(string str) {
    Stack s;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch == '{' || ch == '[' || ch == '(') {
            s.push(ch);
        } else if (ch == '}' || ch == ']' || ch == ')') {
            if (s.empty()) {
                return false; // Unmatched closing parenthesis
            }
            char top = s.pop();
            if ((ch == '}' && top != '{') || (ch == ']' && top != '[') || (ch == ')' && top != '(')) {
                return false; // Mismatched opening and closing parenthesis
            }
        }
    }
    return s.empty(); // Check if all opening parentheses were closed
}

int main() {
    string str;
    cout << "Enter the string: " << endl;
    getline(cin, str);
    if (isValidParenthesis(str)) {
        cout << "String has valid parentheses." << endl;
    } else {
        cout << "String does not have valid parentheses." << endl;
    }
    return 0;
}
