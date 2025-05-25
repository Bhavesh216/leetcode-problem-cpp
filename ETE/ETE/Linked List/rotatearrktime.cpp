#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    vector<int> arr={1,2,3,4,5};
    vector<int> temp(arr.size());
    int k=3;
    for(int i=0;i<arr.size();i++){
        temp[(i+k)%arr.size()]=arr[i];
    }
    for(auto i : temp){
        cout<<i<<" ";
    }
    return 0;
}