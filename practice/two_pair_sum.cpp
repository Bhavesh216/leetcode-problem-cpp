// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;

        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == 0) {
                result.push_back({arr[left], arr[right]});

                // Skip duplicates
                int leftVal = arr[left];
                int rightVal = arr[right];
                while (left < right && arr[left] == leftVal) left++;
                while (left < right && arr[right] == rightVal) right--;
            } 
            else if (sum < 0) {
                left++;
            } 
            else {
                right--;
            }
        }

        return result;
    }
};
