#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    vector<pair<int,int>> v;
    int arr[]={1,2,3,4,9};
    int val =5;
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0])-1;
    while(left<right){
        int sum = arr[left] + arr[right];
        if(sum==val){
            v.push_back(make_pair(arr[left],arr[right]));
            left++;
            right--;
        }
        else if(sum>val){
            right--;
        }
        else{
            left++;
        }
    }
    for(auto i : v){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}