// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
         arr[0]=arr[0]+k;
        for(int i=1;i<n;i++){
            if(arr[i]-k>0){
                arr[i]=arr[i]-k;
            }
            else{
                arr[i]=arr[i]+k;
            }
            }
            return arr[n-1]-arr[0];
    }
};