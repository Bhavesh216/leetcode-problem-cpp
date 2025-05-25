#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int helper(int i, int j, vector<vector<int>> &cost, vector<vector<int>> &dp, int m, int n) {
    // Out of bounds
    if (i >= m || j >= n) return INT_MAX;

    // Reached destination
    if (i == m - 1 && j == n - 1) return cost[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int down = helper(i + 1, j, cost, dp, m, n);
    int right = helper(i, j + 1, cost, dp, m, n);
    int diagonal = helper(i + 1, j + 1, cost, dp, m, n);

    return dp[i][j] = cost[i][j] + min({down, right, diagonal});
}

int minCostPath(vector<vector<int>> &cost, int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(0, 0, cost, dp, m, n);
}


//bottum up 
