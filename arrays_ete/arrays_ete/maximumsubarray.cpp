class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0]; // Initialize maximum sum
    int currentSum = nums[0]; // Initialize current sum

    for (int i = 1; i < nums.size(); i++) {
        // Either continue the current subarray or start a new one
        currentSum = max(nums[i], currentSum + nums[i]);
        // Update the maximum sum
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
};