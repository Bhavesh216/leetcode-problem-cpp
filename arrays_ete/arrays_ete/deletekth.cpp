#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,num,i;
    cout<<"enter number of numbers for input";
    cin>>n;
    cout<<"\n enter the kth element ";
    cin>>k;
    vector<int>vec(n);

    for(i = 0; i < vec.size(); i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    vec.erase(vec.begin()+k-1);

    for ( i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout <<endl;
    return 0;
}