
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(const string& s) {
    vector<int> lastIndex(256, -1); // Array to store the last index of each character
    int maxLength = 0; // Maximum length of substring found
    int left = 0; // Left pointer of the window

    for (int right = 0; right < s.length(); ++right) {
        if (lastIndex[s[right]] >= left) {
            left = lastIndex[s[right]] + 1;
        }
        lastIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    std::string s1 = "abcabcbb";
    std::cout << "Input: " << s1 << ", Output: " << lengthOfLongestSubstring(s1) << std::endl;

    std::string s2 = "bbbbb";
    std::cout << "Input: " << s2 << ", Output: " << lengthOfLongestSubstring(s2) << std::endl;

    std::string s3 = "pwwkew";
    std::cout << "Input: " << s3 << ", Output: " << lengthOfLongestSubstring(s3) << std::endl;

    return 0;
}