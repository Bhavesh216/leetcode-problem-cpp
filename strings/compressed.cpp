#include <iostream>
#include <string>
using namespace std;

string CompressedString(const string& str) {
    string result;
    int count = 1;

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            result += str[i - 1];            // append char
            result += to_string(count);      // append count
            count = 1;
        }
    }

    // Append last group
    result += str.back();                    // or str[str.length() - 1]
    result += to_string(count);

    return result;
}

int main() {
    string input = "aaabbbccc";
    cout << CompressedString(input) << endl;  // Output: a3b3c3
    return 0;
}
