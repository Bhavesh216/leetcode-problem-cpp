#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n,num,num2;
    cout<<"enter number of numbers for input";
    cin>>n;
    vector<int>vec(n);
    vector<int>ans;
    stack<int>s;

    for(int i = 0; i < vec.size(); i++){
        cin>>vec[i];
        num=vec[i];
        s.push(num);
    }
    while(!s.empty()){
    num2=s.top();
    ans.push_back(num2);
    
    s.pop();
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";}
    
    return 0;
}
                                    // for string reversal
// #include<iostream>
// #include<stack>
// using namespace std;



// int main () {
//     string str = "babbar";

//     stack<char> s;

//     for (int i = 0; i<str.length(); i++) {
//         char ch = str[i];
//         s.push(ch);
//     }

//     string ans = "";

//     while(!s.empty()) {
//         char ch = s.top();
//         ans.push_back(ch);

//         s.pop();
//     }

//     cout << "answer is: "<< ans << endl;

//     return 0;
// }