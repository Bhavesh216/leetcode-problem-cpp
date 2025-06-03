#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) return false;
        start++; end--;
    }
    return true;
}

string minCharsToAppend(string str) {
    int n = str.size();

    // If already palindrome, return "NULL"
    if (isPalindrome(str, 0, n - 1))
        return "NULL";

    // Check suffix palindrome from i to end
    for (int i = 1; i < n; i++) {
        if (isPalindrome(str, i, n - 1)) {
            // Append reverse of prefix [0..i-1]
            string toAppend = str.substr(0, i);
            reverse(toAppend.begin(), toAppend.end());
            return toAppend;
        }
    }
    // If no palindrome suffix found (which won't happen), return whole reversed string except last char
    string toAppend = str.substr(0, n - 1);
    reverse(toAppend.begin(), toAppend.end());
    return toAppend;
}

int main() {
    string str;
    cin >> str;

    cout << minCharsToAppend(str) << "\n";
    return 0;
}
