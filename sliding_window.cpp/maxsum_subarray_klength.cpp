class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         unordered_map<int,int> freq;

       int left=0;
       long long maxsum=0;
       long long sum=0;

       for(int right=0;right<nums.size();right++){
        freq[nums[right]]++;
        sum+=nums[right];

        while(right-left+1>k){
            freq[nums[left]]--;
            sum-=nums[left];

            if(freq[nums[left]]==0){
                freq.erase(nums[left]);
            }
            left++;
        }
        if(right-left+1==k && freq.size()==k){
            maxsum = max(maxsum,sum);
        }
       }
       return maxsum;
    }
};