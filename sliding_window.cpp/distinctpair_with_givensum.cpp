vector<vector<int>> findPairsWithSum(vector<int>& arr, int target) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    int left = 0, right = (int)arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            result.push_back({arr[left], arr[right]});

            // Move left and right to next different numbers to avoid duplicates
            int leftVal = arr[left];
            int rightVal = arr[right];
            while (left < right && arr[left] == leftVal) left++;
            while (left < right && arr[right] == rightVal) right--;
        }
        else if (sum < target) {
            left++;
        }
        else { // sum > target
            right--;
        }
    }

    return result;
}