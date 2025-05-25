#include <iostream>
#include <vector>
using namespace std;
// BUTTOM UP
bool subsetSumBottomUp(int arr[], int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base Case: 0 sum is always possible with empty set
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= sum; s++) {
            // Don't pick the current element
            dp[i][s] = dp[i - 1][s];

            // Pick the element if possible
            if (arr[i - 1] <= s)
                dp[i][s] = dp[i][s] || dp[i - 1][s - arr[i - 1]];
        }
    }

    return dp[n][sum];
}
// TOP DOWN 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool subsetSumHelper(int index, int target, int arr[], vector<vector<int>> &dp) {
    // Base Cases
    if (target == 0) return true;  // sum 0 is always possible with empty subset
    if (index == 0) return arr[0] == target;

    // Memoization check
    if (dp[index][target] != -1) return dp[index][target];

    // Option 1: Don't pick the element
    bool notPick = subsetSumHelper(index - 1, target, arr, dp);

    // Option 2: Pick the element if it doesn't exceed the target
    bool pick = false;
    if (arr[index] <= target)
        pick = subsetSumHelper(index - 1, target - arr[index], arr, dp);

    // Store result
    return dp[index][target] = pick || notPick;
}

bool subsetSumTopDown(int arr[], int n, int sum) {
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return subsetSumHelper(n - 1, sum, arr, dp);
}
