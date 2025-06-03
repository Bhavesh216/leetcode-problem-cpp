// User function Template for C++
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        next_permutation(arr.begin(),arr.end());
    }
};





class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=n-1;i>=idx;i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        reverse(arr.begin()+idx+1,arr.end());
        
        
    }
};