#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // If the character is an opening bracket, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        // If the character is a closing bracket
        else {
            // Check if the stack is not empty
            if (!s.empty()) {
                char top = s.top();

                // Check if the top of the stack matches the closing bracket
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;  // Mismatched closing bracket
                }
            } else {
                return false;  // Stack is empty, so no matching opening bracket
            }
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return s.empty();
}

int main() {
    string str;

    cout << "Enter string: ";
    cin >> str;

    bool num = isValid(str);
    cout << (num ? "Valid" : "Invalid") << endl;

    return 0;
}
