#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    string s;
    for(int i=0;i<str.size();i++){
        if(isalnum(str[i]))
            s+=str[i];
    }
    cout<<s.size();
}

int main(){
    int num;
    cin>>num;
    int sum=0;
    int r=0;
    while(num>0){
    int r=num%10;
        sum=sum*10+r;
        num=num/10;
    }
    cou<< sum;

}

int main(){
    string str;
    unordered_map<char,int> freq;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a'|| str[i]=='e'|| str[i]=='i'|| str[i]=='o'|| str[i]=='u')
        freq[str[i]]++;
    }
    vector<pair<char,int> vec;
    for(auto num:freq){
        vec.push_back({num.second,num.first});
    }
    sort(vec.rbegin(),vec.rend());

    cout<<vec.second;
}

string CompressedString(const string& str) {
    stack<int> st;
    vector<char> vec;
    string s;
    st.push(str[0]);
    int count=1;
    for(int i=0;i<str.size();i++){
        if(str[i]==st.top()){
            int count++;
        }
        else{
           s+=str[i];
           s+=to_string(count);
        }
    }
}