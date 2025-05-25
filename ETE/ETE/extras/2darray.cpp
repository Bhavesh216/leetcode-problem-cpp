// #include <bits/stdc++.h>
// using namespace std;
// int colSum(vector<vector<int>>&arr,int n,int m){
//     int maxSum=0;
//     for(int j=0;j<m;j++){
//         int sum = 0;
//         for(int i=0;i<n;i++){
//             sum+=arr[i][j];
//         }
//         if(sum > maxSum){
//             maxSum = sum;
//         }
//     }
//     return maxSum;
// }

// int main() {
//     // Your code here
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> arr(n,vector<int>(m));
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     int col = colSum(arr,n,m);
//     cout<<col<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int colSum(vector<vector<int>>& arr, int n, int m) {
    int maxSum = 0;
    for(int j = 0; j < m; j++) { // Iterate over columns
        int sum = 0;
        for(int i = 0; i < n; i++) { // Iterate over rows for each column
            sum += arr[i][j];
        }
        if(sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m)); // Initialize the 2D vector

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j]; // Input the elements of the 2D vector
        }
    }

    int col = colSum(arr, n, m);
    cout << col << endl;
    return 0;
}
