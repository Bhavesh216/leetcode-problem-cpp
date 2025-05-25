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
Node* sortedArrtoBst(int arr[],int start,int end){
    if(start>end){
        return nullptr;
    }
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrtoBst(arr,start,mid-1);
    root->right = sortedArrtoBst(arr,mid+1,end);

    return root;
}
void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {

    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = sortedArrtoBst(arr,0,n-1);
    preorder(root);
    
    return 0;
}