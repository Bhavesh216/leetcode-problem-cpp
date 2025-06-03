// User function Template for C++
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // Your Code Here

    int n = arr.size();

    // Initialize max and min product ending at current index
    int maxEndingHere = arr[0];
    int minEndingHere = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        // If current number is negative, swap max and min
        if (arr[i] < 0)
            swap(maxEndingHere, minEndingHere);

        maxEndingHere = max(arr[i], arr[i] * maxEndingHere);
        minEndingHere = min(arr[i], arr[i] * minEndingHere);

        result = max(result, maxEndingHere);
    }

    return result;
}
};