class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Step 1: Sort the intervals by start time
        sort(arr.begin(), arr.end());

        // Step 2: Use a result vector and index tracker
        vector<vector<int>> merged;
        merged.push_back(arr[0]);
        int idx = 0;  // Tracks last position in merged

        for (int i = 1; i < arr.size(); i++) {
            // If intervals overlap, merge them
            if (merged[idx][1] >= arr[i][0]) {
                merged[idx][1] = max(merged[idx][1], arr[i][1]);
            } else {
                // No overlap; move to next slot
                merged.push_back(arr[i]);
                idx++;
            }
        }

        return merged;
    }
};
