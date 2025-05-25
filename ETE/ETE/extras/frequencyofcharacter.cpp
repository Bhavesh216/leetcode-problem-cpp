// #include <bits/stdc++.h>
// using namespace std;
// void frequency(string s){
//     map<char,int> m;

//     for(int i=0;i<s.length();i++){
//         if(m.find(s[i])==m.end()){
//             m.insert(make_pair(s[i],1));
//         }
//         else{
//             m[s[i]]++;
//         }
//     }
//     int min = 0;
//     char c;
//     for(auto i:m){
//         if(i.second>=min){
//             c=i.first;
//             min = i.second;
//         }
//     }
//     cout<<c<<" ";
// }
// int main() {
//     string str = "";
//     frequency(str);    

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
void freq(string s){
    int n = s.length();
    map<char,int> m;
    for(int i=0;i<n;i++){
        if(m.find(s[i])==m.end()){
            m.insert(make_pair(s[i],1));
        }
        else{
            m[s[i]]++;
        }
    }
    int min = 0;
    char c ;
    for(auto i : m){
        if(i.second>min){
            min = i.second;
            c = i.first;
        }
    }
    cout<<c<<endl;
}
int main() {
    // Your code here
    string str = "geeksforgeeks";
    freq(str);
    return 0;
}