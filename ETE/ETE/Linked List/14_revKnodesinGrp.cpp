#include <bits/stdc++.h>
using namespace std;
void revinKgroups(vector<int> &arr,int k){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < n ; i+=k){
        int left = i;
        int right = min(i+k-1,n-1);

        while(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    revinKgroups(arr,3);
    for(auto i : arr){
        cout<<i<<" ";
    }
    
    return 0;
}