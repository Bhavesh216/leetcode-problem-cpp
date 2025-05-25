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

bool isSymmetric(Node* left, Node* right){
    if(left==nullptr ||right ==nullptr){
        return left==right;
    }
    if(left->data!=right->data){return false;}

    return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
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
    bool val = isSymmetric(root->left,root->right)?true:false;
    if(val){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}