#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node* arrTree(vector<int>&arr , int size){
    if(size == 0 ) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i=1;
    while(i<size){
        Node* temp = q.front();
        q.pop();
        
        if(arr[i]!=-1){
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(arr[i]!=-1 && i<size){
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
vector<vector<int>> VOT(Node* &root){
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    map<int,map<int,vector<int>>> m;
    queue<pair<Node*,pair<int,int>>> q;
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()){
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        m[hd][lvl].push_back(frontNode->data);
        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i : m){
        vector<int>cols;
        for(auto j : i.second){
            cols.insert(cols.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(cols);
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    string str;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="null"||str=="-1"){
            arr[i]=-1;
        }
        else{
            arr[i] = stoi(str);
        }
    }
    Node* root = arrTree(arr,n);
    vector<vector<int>> ans = VOT(root);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;  
}