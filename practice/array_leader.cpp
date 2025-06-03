

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> vec;
        int n=arr.size();
        int maxl=arr[n-1];
        vec.push_back(maxl);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxl){
                maxl=arr[i];
                vec.push_back(arr[i]);
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};