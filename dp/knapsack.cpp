#include <vector>
#include <algorithm>
using namespace std;
//  BUTTOMS UP APPROACH
int zeroOneKnapsack(int values[], int weights[], int numItems, int capacity) {
    // Create DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(numItems + 1, vector<int>(capacity + 1, 0));

    // Build table from bottom-up
    for (int i = 1; i <= numItems; i++) {
        for (int w = 1; w <= capacity; w++) {
            // Current item's index in arrays is i-1 (since i starts from 1)
            int currentWeight = weights[i-1];
            int currentValue = values[i-1];
            
            if (currentWeight <= w) {
                // Can include this item: choose max between including or excluding
                dp[i][w] = max(
                    currentValue + dp[i-1][w - currentWeight],  // Include item
                    dp[i-1][w]                                 // Exclude item
                );
            } else {
                // Can't include this item
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[numItems][capacity];
}

// TOP DOWN APPROACH
#include <vector>
#include <algorithm>
using namespace std;

int knapsackHelper(int values[], int weights[], int items, int capacity, vector<vector<int>>& dp) {
    // Base Case 1: No items left or no capacity left
    if (items == 0 || capacity == 0) {
        return 0;
    }

    // Return precomputed result if available
    if (dp[items][capacity] != -1) {
        return dp[items][capacity];
    }

    // Current item's weight exceeds remaining capacity - can't include it
    if (weights[items-1] > capacity) {
        dp[items][capacity] = knapsackHelper(values, weights, items-1, capacity, dp);
    }
    else {
        // We have two choices:
        // 1. Include current item: add its value and reduce capacity
        int include = values[items-1] + knapsackHelper(values, weights, items-1, capacity - weights[items-1], dp);
        
        // 2. Exclude current item: move to next item without changing capacity
        int exclude = knapsackHelper(values, weights, items-1, capacity, dp);
        
        // Store the better of the two options
        dp[items][capacity] = max(include, exclude);
    }

    return dp[items][capacity];
}

int zeroOneKnapsack(int values[], int weights[], int numItems, int capacity) {
    // Initialize DP table with -1 (uncomputed states)
    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(numItems + 1, vector<int>(capacity + 1, -1));
    
    return knapsackHelper(values, weights, numItems, capacity, dp);
}