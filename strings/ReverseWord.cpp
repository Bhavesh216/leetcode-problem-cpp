#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s); // Create a stringstream object for input string
    string word;
    vector<string> words;

    // Split the string into words and store them in a vector
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Concatenate words into a single string with spaces
    string result;
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) result += " "; // Add a space before each word except the first
        result += words[i];
    }

    return result;
}

int main() {
    string s = "  hello world  ";
    cout << reverseWords(s) << endl; // Output: "world hello"
    return 0;
}

getline(cin,string);