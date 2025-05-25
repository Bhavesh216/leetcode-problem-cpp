#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    // Remove non-alphanumeric characters and convert to lowercase
    string filtered;
    for (int i = 0; i < s.size(); ++i) {
        if (isalnum(s[i])) {
            filtered += tolower(s[i]);
        }
    }

    // Check if the filtered string is equal to its reverse
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());

    return filtered == reversed;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        cout << "The string is a palindrome!" << endl;
    } else {
        cout << "The string is not a palindrome!" << endl;
    }
    return 0;
}


