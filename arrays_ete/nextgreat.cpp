#include<bits/stdc++.h>
using namespace std;

int  main(){
    int n,i;
    cout<<"\n enter numbers of inputs";
    cin>>n;

    vector<int>vec(n);
    for(i=0;i<vec.size();i++){
        cin>>vec[i];
    }
    for(i=0;i<vec.size();i++){
        if(vec[i]<vec[i+1]){
            cout<<vec[i+1];
        }
        else{
            cout<<-1;
        }
    }
    
    
}