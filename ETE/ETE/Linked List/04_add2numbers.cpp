#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    vector<int>brr(m);
    int a=0,b=0;
    for(int i=n-1;i>=0;i--){
        cin>>arr[i];
    }
    for(int i=m-1;i>=0;i--){
        cin>>brr[i];
    }

    for(auto i : arr){
        a = a*10 + i;
    }
    for(auto i : brr){
        b=b*10+i;
    }
    int c = a+b;
    cout<<c<<endl;
    // vector<int> crr;
    // while(c>0){
    //     int d = c%10;
    //     crr.push_back(d);
    //     c=c/10;
    // }
    // // reverse(crr.begin(),crr.end());
    // for(auto i : crr){
    //     cout<<i<<" ";
    // }
    int r=0;
    while(c>0){
        int d = c%10;
        r = r*10+d;
        c = c/10;
    }
    cout<<r<<endl;
    return 0;
}