#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[]={3,1,4,6,2};
    int brr[]={1,2,4,5,4,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(brr)/sizeof(brr[0]);
    int i = n-1;
    int j = m-1;
    int intersection;
    while(i>=0 && j>=0){
        if(arr[i]==brr[j]){
            intersection = arr[i];
            i--;
            j--;
        }
        else{
            break;
        }
    }
    cout<<intersection<<endl;
    return 0;
}