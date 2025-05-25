int countWays(int D, int K) {
    vector<int> dp(D + 1, 0);
    dp[0] = 1;  // Only one way to stay at ground (no move)

    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[D];
}