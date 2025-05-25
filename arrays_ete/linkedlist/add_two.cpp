#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10],arr1[10],i,n,m,a=0,b=0,c=0;
    cin>>n>>m;

    for(i=n-1;i>=0;i--){
        cin>>arr[i];
    }
    for(i=m-1;i>=0;i--){
        cin>>arr1[i];
    }

    for(i=0;i<n;i++){
          a=a*10+arr[i];
    }

     for(i=0;i<m;i++){
          b=b*10+arr1[i];
    }

    c=a+b;
    int r=0;
    vector<int>v;
    while(c>0){
        r=c%10;
        v.push_back(r);
        c=c/10;
    }
    reverse(v.begin(),v.end());
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}