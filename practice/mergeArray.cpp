class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    
    for (int i = 0; i < n; i++) {
        if (a[i] > b[0]) {
            swap(a[i], b[0]);
            sort(b.begin(),b.end());
            // int first=b[0];
            // int k = 1;
            // while (k < m && b[k] < first) {
            //     b[k - 1] = b[k];
            //     k++;
            // }
            // b[k - 1] = first;
            
        }
    }
        
    }
};