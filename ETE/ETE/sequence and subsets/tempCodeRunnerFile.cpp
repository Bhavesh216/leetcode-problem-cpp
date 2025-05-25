#include <bits/stdc++.h>
using namespace std;
vector<string> power(string s){
    int n = s.length();
    vector<string> ans; 
    for(int i=0;i<pow(2,n);i++){
        string str = "";
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                str+=s[j];
            }
        }
        if(str.length()>0){
            ans.push_back(str);
        }
    }
    return ans;
}
int main() {

    string s = "abc";
    vector<string> set = power(s);
    for(auto i : set){
        cout<<i<<" ";
    }
    
    return 0;
}