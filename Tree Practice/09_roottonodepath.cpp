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
Node* arrTree(vector<int>&arr, int size){
    if(size==0){
        return nullptr;
    }
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<size){
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
bool RootToNodePath(Node* root, vector<int>&arr, int x){
    if(!root) return false;

    arr.push_back(root->data);
    if(root->data==x){
        return true;
    }

    if(RootToNodePath(root->left,arr,x) || RootToNodePath(root->right,arr,x)){
        return true;
    }
    arr.pop_back();
    return false;
}
int main() {

    int n;
    cin>>n;
    string str;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>str;
        if(str == "null"||str=="-1"){
            arr[i]=-1;
        }
        else{
            arr[i]=stoi(str);
        }
    }
    int tar;
    cin>>tar;
    Node* root = arrTree(arr,n);
    vector<int>res;
    bool path = RootToNodePath(root,res,tar);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}