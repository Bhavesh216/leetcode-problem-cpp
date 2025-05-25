#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int arr[]={1,1,1,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]!=s.top()){
            s.push(arr[i]);
        }
    }
    vector<int> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    for(int i = res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
    return 0;
}