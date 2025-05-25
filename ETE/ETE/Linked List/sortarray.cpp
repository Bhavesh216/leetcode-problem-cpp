#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    vector<int>arr={5,4,3,2,1};
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}