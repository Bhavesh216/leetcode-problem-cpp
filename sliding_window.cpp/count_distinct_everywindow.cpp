class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int,int> freq;
        int left=0;
        vector<int> v;
        for(int right=0;right<arr.size();right++){
            freq[arr[right]]++;
            
            while(right-left+1>k){
                freq[arr[left]]--;
                if(freq[arr[left]]==0){
                    freq.erase(arr[left]);
                }
                left++;
            }
            if(right-left+1==k){
                v.push_back(freq.size());
            }
        }
        return v;
    }
};
