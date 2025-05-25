#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to insert a new node with given data in BST
node* insertbst(node* root, int d) {
    if (root == nullptr) {
        root = new node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertbst(root->right, d);
    } else if (d < root->data) {
        root->left = insertbst(root->left, d);
    }
    return root;
}

// Function to take input of array and insert elements into BST
void takeinput(node*& root) {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        root = insertbst(root, arr[i]);
    }
}
// node* takeinput(node * &root){
//     int data;
//     cin>>data;

//     while(data!=-1){
//         root= insertbst(root,data);
//         cin>>data;
//     }
// }

node* minival(node * root){
    node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
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
            int mini = minival(root->right)->data;
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

// Function to print BST in inorder 
void inorder(node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* sortedArrtoBst(int arr[],int start,int end){
    if(start>end){
        return nullptr;
    }
    int mid = (start+end)/2;
    node* root = new node(arr[mid]);

    root->left = sortedArrtoBst(arr,start,mid-1);
    root->right = sortedArrtoBst(arr,mid+1,end);

    return root;
}

int main() {
    node* root = nullptr;
    takeinput(root);
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    //Node* root = sortedArrtoBst(arr,0,n-1);

    // Output the inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
