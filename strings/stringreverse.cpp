string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());  // Reverse the string in-place
    return reversed;
}