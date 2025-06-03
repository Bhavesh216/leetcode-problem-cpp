
// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
    int n = s.size();

    // Start checking from largest possible prefix length
    for (int len = n - 1; len > 0; len--) {
        bool match = true;

        // Compare prefix and suffix of length 'len'
        for (int i = 0; i < len; i++) {
            if (s[i] != s[n - len + i]) {
                match = false;
                break;
            }
        }

        if (match) return len; // Found longest prefix = suffix
    }

    return 0; // No prefix equals suffix found
    }
};