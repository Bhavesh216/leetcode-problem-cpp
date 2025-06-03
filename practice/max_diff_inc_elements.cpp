int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minSoFar) {
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
                minSoFar = nums[i];  // Update min for future comparisons
            }
        }

        return maxDiff;
    }



    class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int mindiff=-1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i]&&nums[j]-nums[i]>mindiff){
                    mindiff=nums[j]-nums[i];
                }
            }
        }
        return mindiff;
    }
};

