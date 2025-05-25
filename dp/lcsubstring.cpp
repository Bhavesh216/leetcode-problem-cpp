#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int maxLen = 0;  // to store length of longest common substring
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";
    
    cout << longestCommonSubstring(s1, s2) << "\n";  // Output: 4
    return 0;
}


//top down
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcsHelper(const string& s1, const string& s2, int i, int j, int count, vector<vector<vector<int>>>& dp) {
    if (i == s1.size() || j == s2.size())
        return count;
    
    if (dp[i][j][count] != -1)
        return dp[i][j][count];
    
    int c1 = count;
    if (s1[i] == s2[j])
        c1 = lcsHelper(s1, s2, i + 1, j + 1, count + 1, dp);
    
    int c2 = lcsHelper(s1, s2, i + 1, j, 0, dp);
    int c3 = lcsHelper(s1, s2, i, j + 1, 0, dp);
    
    return dp[i][j][count] = max(c1, max(c2, c3));
}

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    // 3D DP: dp[i][j][count]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(min(n,m) + 1, -1)));
    
    return lcsHelper(s1, s2, 0, 0, 0, dp);
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    cout << longestCommonSubstring(s1, s2) << endl;  // Output: 4
    return 0;
}
