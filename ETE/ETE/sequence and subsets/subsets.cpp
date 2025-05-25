// #include <bits/stdc++.h>
// using namespace std;
// vector<string> power(string s){
//     int n = s.length();
//     vector<string> ans; 
//     for(int i=0;i<pow(2,n);i++){
//         string str = "";
//         for(int j=0;j<n;j++){
//             if(i & (1<<j)){
//                 str+=s[j];
//             }
//         }
//         if(str.length()>0){
//             ans.push_back(str);
//         }
//     }
//     return ans;
// }
// int main() {

//     string s = "abc";
//     vector<string> set = power(s);
//     for(auto i : set){
//         cout<<i<<" ";
//     }
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> power(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>> res;
    for(int i=0;i<pow(2,n);i++){
        vector<int> r;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                r.push_back(arr[j]);
            }
        }
        if(r.size()>0){
            res.push_back(r);
        }
    }
    return res;
}
int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = power(arr);

    vector<vector<int>> ans;
    for(auto i : res){
        int sum = 0;
        for(auto j : i){
            sum+=j;
        }
        if(sum==3){
            ans.push_back(i);
        }
    }
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    


    return 0;
}