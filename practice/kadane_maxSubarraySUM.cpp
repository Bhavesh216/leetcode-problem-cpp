#include<climits>
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
            int n  = arr.size();
            int maxsum = INT_MIN;
            int sum = 0;
            for(int i = 0; i<n ; i++){
              sum+=arr[i];
                            maxsum = max(sum,maxsum);
            
            if(sum<0){
                sum=0;
            }
            }
    return maxsum;
        
    }

};