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
int treeSum(Node* root, int val){
    if(root==NULL) return 0;
    val = val*10+root->data;

    if(root->left==NULL && root->right==NULL){
        return val;
    }

    return treeSum(root->left,val)+treeSum(root->right,val);
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
            arr[i]=stoi(str);
        }
    }
    Node* root = arrTree(arr,n);
    int result = treeSum(root,0);
    cout<<result<<endl;
    
    return 0;
}