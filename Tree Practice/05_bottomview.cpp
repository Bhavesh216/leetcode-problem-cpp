#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        left = nullptr;
        right = nullptr;
    }
};
Node* arrTree(vector<int>&arr, int size){
    if(size==0) return nullptr;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    while(i<size && !q.empty()){
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
vector<int> topView(Node* root){
    vector<int> ans;
    if(root==nullptr) return ans;
    map<int,int> m;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> t = q.front();
        q.pop();

        Node* temp = t.first;
        int line = t.second;
        m[line]=temp->data;
        if(temp->left){
            q.push(make_pair(temp->left,line-1));
        }
        if(temp->right){
            q.push(make_pair(temp->right,line+1));
        }
    }
    for(auto i : m){
        ans.push_back(i.second);
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    string str;
    vector<int>arr(n);
    vector<int> ans; 
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="null"||str=="-1"){
            arr[i] = -1;
        }
        else{
            arr[i] = stoi(str);
        }
    }
    Node* root = arrTree(arr,n);
    ans = topView(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}