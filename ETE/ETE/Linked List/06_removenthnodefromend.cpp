#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = n-3;
    int brr[n-1];
    int j=0;
    for(int i=0;i<n;i++){
        if(i==k){
            continue;
        }       
        brr[j++]=arr[i];
    }
    for(auto i : brr){
        cout<<i<<" ";
    }
    return 0;
}