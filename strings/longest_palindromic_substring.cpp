string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    // return the valid palindrome substring
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    string longest = "";

    for (int i = 0; i < s.length(); i++) {
        // Odd-length palindromes
        string odd = expandAroundCenter(s, i, i);
        if (odd.length() > longest.length()) longest = odd;

        // Even-length palindromes
        string even = expandAroundCenter(s, i, i + 1);
        if (even.length() > longest.length()) longest = even;
    }

    return longest;
}
