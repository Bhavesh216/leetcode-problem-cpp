#include <bits/stdc++.h>
using namespace std;
vector<string> subseq(string s){
    int n = s.length();
    vector<string> sequence;
    for(int i=0;i<n;i++){
        for(int j=i;j<=n;j++){
            string st = "";
            for(int k=i;k<=j;k++){
                st+=s[k];
            }
            sequence.push_back(st);
        }
    }
    return sequence;
}
int main() {
    string s = "unique";
    vector<string> seq = subseq(s);
    for(auto i : seq){
        cout<<i<<endl;
    }
    return 0;
}