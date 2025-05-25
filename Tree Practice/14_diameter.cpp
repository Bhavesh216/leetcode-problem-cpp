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
int height(Node* &root){
    if(root==nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}
int diameter(Node* &root){
    if(root==nullptr) return 0;

    int left = diameter(root->left);
    int right = diameter(root->right);
    int dia = height(root->left)+height(root->right);

    return (max(left,max(right,dia)));
}
int main() {
    int n;
    cin>>n;
    string str;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="-1"||str=="null"){
            arr[i]=-1;
        }
        else{
            arr[i]=stoi(str);
        }
    }
    Node* root = arrTree(arr,n);
    
    cout<<diameter(root);
    
    return 0;
}