#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *left;
    node *right;

    public:
    node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

node *insertintoBST(node *root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertintoBST(root->right, d);
    }

    if(d < root-> data){
        root->left = insertintoBST(root->left, d);
    }

    return root;
}

void takeinput(node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertintoBST(root, data);
        cin>>data;
    }
}

node* miniVal(node *root){
    node *temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

node *maxVal(node *root){
    node *temp = root;

    while(temp->right!=NULL){
        temp = temp -> right;
    }
    return temp;
}

node *deletion(node *root, int val){
    if(root==NULL){
        return root;
    }

    if(root->data == val){
        // 0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left
        if(root->left!=NULL && root->right==NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }

        //right
        if(root->left==NULL && root->right!=NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left!=NULL && root->right!=NULL){
            int mini = miniVal(root->right)->data;
            root->data = mini;
            root->right = deletion(root->right, mini);
            return root;
        }
    }
    else if(val > root->data){
        root->right = deletion(root->right, val);
    }
    else if(val < root->data){
        root->left = deletion(root->left, val);
    }
    return root;
}

int main(){
    node *root = NULL;

    cout<<"Enter the data to create BST"<<endl;
    takeinput(root);
    
}