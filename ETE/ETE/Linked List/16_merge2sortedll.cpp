#include <bits/stdc++.h>
using namespace std;
void bubblesort(vector<int> &arr){
    int n =arr.size();
    for(int i = 0 ;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main() {
    vector<int> arr = {2,4,8,10};
    vector<int> brr = {1,3,3,6,11,14};
    for(auto i:brr){
        arr.push_back(i);
    }
    bubblesort(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    
    return 0;
}