#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    vector<int> arr = {1,2,3,4,5};
    vector<int> brr(arr.size());
    int k = 2;
    for(int i=0;i<arr.size();i++){
        brr[(i+k)%arr.size()] = arr[i];
    }
    for(auto i : brr){
        cout<<i<<" ";
    }
    return 0;
}