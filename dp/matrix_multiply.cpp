#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int arr[], int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 2; len < N; ++len) {  // chain length
        for (int i = 1; i < N - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][N-1];  // Full range (1 to N-1)
}


//top down 
#include <bits/stdc++.h>
using namespace std;

// Matrix A[i] has dimension p[i-1] x p[i]  for i = 1 to n
int dp[101][101]; // memoization table

int matrixChainMemo(int p[], int i, int j) {
    if (i >= j) return 0; // Base case: no cost when one or no matrix

    if (dp[i][j] != -1) return dp[i][j]; // Return memoized result

    int minCost = INT_MAX;

    // Try all possible places to split the chain
    for (int k = i; k < j; k++) {
        int cost = matrixChainMemo(p, i, k)      // Cost of multiplying A[i..k]
                 + matrixChainMemo(p, k + 1, j)  // Cost of multiplying A[k+1..j]
                 + p[i - 1] * p[k] * p[j];       // Cost of final multiplication

        minCost = min(minCost, cost); // Keep track of minimum
    }

    return dp[i][j] = minCost; // Memoize and return
}

int matrixChainMultiplication(int p[], int n) {
    memset(dp, -1, sizeof(dp)); // Initialize memo table
    return matrixChainMemo(p, 1, n - 1); // Start from matrix 1 to n-1
}
