#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[]={1,2,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num=0;
    for(int i=0;i<n;i++){
        num = num*10 + arr[i];
    }
    int NUM = num;
    int r = 0;
    while(NUM>0){
        int d = NUM%10;
        r = r*10 + d;
        NUM = NUM/10;
    }
    if(r==num){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}