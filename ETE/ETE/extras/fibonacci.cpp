// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     // Your code here
//     int n;
//     cin>>n;
//     int t1,t2;
//     int nextTerm;
//     for(int i=0;i<n;i++){
//         if(i==0){
//             t1=0;
//             cout<<i<<" ";
//             continue;
//         }
//         if(i==1){
//             t2=1;
//             cout<<i<<" ";
//             continue;
//         }
//         nextTerm = t1+t2;
//         cout<<nextTerm<<" ";
//         t1 = t2;
//         t2 = nextTerm;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    // Your code here
    int n;
    cin>>n;
    int a = 0;
    int b = 1;
    int c;
    for(int i=0;i<n-1;i++){
        if(i==0) cout<<a<<" ";
        if(i==1) cout<<b<<" ";
        else{
        c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
        }
    }
    return 0;
}