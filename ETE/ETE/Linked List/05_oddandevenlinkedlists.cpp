#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[]={1,0,1,2,0,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}