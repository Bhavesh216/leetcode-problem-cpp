// #include <bits/stdc++.h>
// using namespace std;
// vector<int> NGE(vector<int>&arr){
//     int n = arr.size();
//     vector<int> nge (n,-1);
//     stack<int> s;
//     for(int i=n-1;i>=0;i--){
//         while(!s.empty() && arr[i]>=s.top()){
//             s.pop();
//         }
//         if(!s.empty()){
//             nge[i]=s.top();
//         }
//         s.push(arr[i]);
//     }
//     return nge;
// }
// int main() {
//     // Your code here
//     vector<int> arr = {13,7,6,12};
//     vector<int> nge = NGE(arr);
//     for(auto i : nge){
//         cout<<i<<" "; 
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<int> NGE(vector<int>&arr){
    int n = arr.size();
    vector<int> nge(n,-1);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&& arr[i]>=s.top()){
            s.pop();
        }
        if(!s.empty()){
            nge[i]=s.top();
        }
        s.push(arr[i]);
    }
    return nge;
}
int main() {
    vector<int> arr = {4,5,2,25};
    vector<int> nge = NGE(arr);
    for(auto i : nge){
        cout<<i<<" ";
    }
    return 0;
    return 0;
}