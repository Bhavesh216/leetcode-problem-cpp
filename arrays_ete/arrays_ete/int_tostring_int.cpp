#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Given integer N
    int N = 123;

    // Convert the integer to a string
    string str = to_string(N);

    // Create a vector to store the digits
    vector<int> digitArray;

    // Iterate over each character in the string
    for(char digit : str) {
        // Convert the character to an integer and store it in the vector
        digitArray.push_back(digit - '0'); // '0' is subtracted to get the integer value of the char
    }

    // Print the resulting array
    cout << "Array of digits: ";
    for(int digit : digitArray) {
        cout << digit << " ";
    }
    cout << endl;

    // Convert the array of digits back into a string
    // Method 1: Using std::to_string
    string result1;
    for(int digit : digitArray) {
        result1 += to_string(digit);
    }
    cout << "Resulting string using to_string: " << result1 << endl;

    // Method 2: Using std::ostringstream
    ostringstream oss;
    for(int digit : digitArray) {
        oss << digit;
    }
    string result2 = oss.str();
    cout << "Resulting string using ostringstream: " << result2 << endl;

    return 0;
}
