#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int total = 0;
    sort(arr, arr+n);

    for(int i=0; i<n-1; i++){
        arr[i+1] = arr[i+1] + arr[i];
        total = total + arr[i+1];
        sort(arr, arr+n);
    }

    cout<<total;
}