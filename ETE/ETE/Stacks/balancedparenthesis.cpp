// #include <bits/stdc++.h>
// using namespace std;
// bool match(char a,char b){
//     if(a=='('&&b==')'){
//         return true;
//     }
//     if(a=='{'&&b=='}'){
//         return true;
//     }
//     if(a=='['&&b==']'){
//         return true;
//     }
//     return false;
// }
// bool valid(string s){
//     stack<char> st;
//     for(int i=0;i<s.length();i++){
//         if(s[i]=='('||s[i]=='{'||s[i]=='['){
//             st.push(s[i]);
//         }
//         if(s[i]==')'||s[i]=='}'||s[i]==']'){
//             if(!st.empty() && match(st.top(),s[i])){
//                 st.pop();
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     return st.empty();
// }
// int main() {

//     cout<<valid("({[]})");
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
bool match(char a,char b){
    if(a=='{'&&b=='}'){
        return true;
    }
    if(a=='['&&b==']'){
        return true;
    }
    if(a=='('&&b==')'){
        return true;
    }
    else return false;
}
bool valid(string s){
    int n = s.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                    if(!st.empty() && match(st.top(),s[i])){
                        st.pop();
                    }
                    else{
                        return false;
                    }
            }
    }
    return st.empty();
}
int main() {
    cout<<valid("((()))");
    return 0;
}