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
Node* buildTree(Node* root){
    int data;
    cin>>data;
    if(data==-1) return nullptr;

    root = new Node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}
void LOT(Node* root){
    if(root==nullptr) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
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
int main() {
    Node* root = nullptr;
    root = buildTree(root);
    LOT(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}