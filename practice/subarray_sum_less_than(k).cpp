class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
    int n = arr.size();
    int minLength = n + 1;
    int currentSum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        // Try to shrink the window
        while (currentSum > x) {
            minLength = min(minLength, right - left + 1);
            currentSum -= arr[left];
            left++;
        }
    }

    // If no valid subarray was found, return 0
    return (minLength == n + 1) ? 0 : minLength;

    }
};