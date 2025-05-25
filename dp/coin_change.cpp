#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // Initialize DP array with "infinity" (amount + 1 is impossible)
    vector<int> dp(amount + 1, amount + 1);
    
    // Base case: 0 coins needed to make amount 0
    dp[0] = 0;
    
    // Fill the DP table
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    // Return result with if-else
    if (dp[amount] == amount + 1) {
        return -1;  // No solution exists
    } else {
        return dp[amount];  // Return minimum coins needed
    }
}