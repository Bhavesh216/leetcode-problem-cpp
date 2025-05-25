#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,count,n,j;
    cout<<"\n enter number of stocks";
    cin>>n;
    stack<int>s;
    vector<int>v(n);

    for(i=0;i<n;i++){
        cin>>v[i];
    }

    for(i=n-1;i>=0;i--){
        count=1;
        for(j=i-1;j>0;j--){
            if(v[i]>v[j]){
                count++;
            }
        }
        s.push(count);
    }
    int arr[n];
    int i =0;
    while(!s.empty()){
        arr[i]=s.top();
        i++;
        s.pop();
    }

    for(i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}