#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[]={10,4,10,10,6,10};
    int brr[10]={0};
    int j=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==10){
            continue;
        }
        else{
            brr[j]=arr[i];
            j++;
        }
    }    
    for(auto i:brr){
        if(i!=0){
            cout<<i<<" ";
        }
    }
    return 0;
}