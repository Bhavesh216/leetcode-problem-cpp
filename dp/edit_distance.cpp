class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // Memoization table
        return helper(word1, word2, m, n, dp);
    }

    int helper(string& word1, string& word2, int m, int n, vector<vector<int>>& dp) {
        if (m == 0) return n; // word1 is empty → insert all of word2
        if (n == 0) return m; // word2 is empty → delete all of word1

        if (dp[m][n] != -1) return dp[m][n]; // already computed

        if (word1[m - 1] == word2[n - 1]) {
            return dp[m][n] = helper(word1, word2, m - 1, n - 1, dp); // last chars match → skip both
        }

        // Try all 3 operations: delete, insert, replace
        return dp[m][n] = 1 + min({
            helper(word1, word2, m - 1, n, dp),     // Delete from word1
            helper(word1, word2, m, n - 1, dp),     // Insert into word1
            helper(word1, word2, m - 1, n - 1, dp)  // Replace in word1
        });
    }
};
