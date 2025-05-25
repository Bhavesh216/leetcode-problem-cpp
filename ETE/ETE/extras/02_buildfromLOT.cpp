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
void BuildFromLot(Node* &root){
    int n;
    cin>>n;
    root = new Node(n);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void LOT(Node* root){
    if(root == nullptr){
        return ;
    }
    queue<Node*>q ;
    q.push(root);  
    q.push(nullptr);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == nullptr){
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
    BuildFromLot(root);
    LOT(root);
    
    return 0;
}