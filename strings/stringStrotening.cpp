#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        if (s.empty()) {
            return "empty string";
        }

        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
