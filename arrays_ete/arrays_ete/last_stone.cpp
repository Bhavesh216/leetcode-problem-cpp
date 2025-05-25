#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int size = n;

    while(size>1){
        sort(arr, arr+size);

        if(arr[size-1] == arr[size-2]){
            size = size - 2;
        }
        else{
            arr[size-2] = arr[size-1] - arr[size-2];
            size--;
        }
    }

    if(size==1){
        cout<<arr[0];
    }
    else{
        cout<<0;
    }
}