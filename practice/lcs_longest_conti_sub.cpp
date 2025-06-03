class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
    sort(arr.begin(),arr.end());
    int maxlen=1;
    int currlen=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]){
           continue;
        }
        else if(arr[i]==arr[i-1]+1){
         currlen++;
        }
        else currlen=1;
        maxlen=max(maxlen,currlen);
    }
    return maxlen;
}
};