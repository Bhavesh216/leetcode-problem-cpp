#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //return dp[n][m]; // The length of the LCS
     int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        // If characters match, it's part of LCS
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        // Move in the direction of greater value
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end()); // LCS is built in reverse
    return lcs;
}


int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << "Length of LCS: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
// top down
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsUtil(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i == s1.length() || j == s2.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsUtil(s1, s2, i + 1, j + 1, dp);
    else
        return dp[i][j] = max(lcsUtil(s1, s2, i + 1, j, dp),
                              lcsUtil(s1, s2, i, j + 1, dp));
}

int lcs(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsUtil(s1, s2, 0, 0, dp);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}
