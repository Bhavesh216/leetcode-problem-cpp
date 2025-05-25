#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cout<<"Enter the number of elements";
    cin>>x;

    int arr[x];

    for(int i=0; i<x; i++){
        cin>>arr[i];
    }

    int max = -1;
    for(int i=1; i<x; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    cout<<max;
}