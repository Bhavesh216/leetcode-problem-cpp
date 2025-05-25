#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cout<<"enter the number of nodes";
    cin>>n;
    cout<<"\n enter the number of edges";
    cin>>m;
    vector<int> adj[m];

  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
