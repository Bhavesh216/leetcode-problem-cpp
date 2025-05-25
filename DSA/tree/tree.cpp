#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"Enter data for the node : "<<endl;
    string data;
    cin>>data;
    root = new Node(data);

    if(data=='null'){
        return NULL;
    }

    cout<<"Enter data for inserting at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting at right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root; 
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //seperator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL) //purana level complete
        {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }  
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void Preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node* root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main() {

    Node* root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Level Order Traversal is : "<<endl;
    levelOrderTraversal(root);
    cout<<"Preorder Traversal is : "<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal is : "<<endl;
    Postorder(root);
    cout<<endl;
    cout<<"Inorder Traversal is : "<<endl;
    Inorder(root);
    return 0;
}