// BUILD TREE NORMAL AND TRAVERSALS

// #include <bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int d){
//         this->data = d;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };
// Node* buildTree(Node* root){
//     int data;
//     cin>>data;
//     if(data == -1){
//         return nullptr;
//     }

//     root = new Node(data);
//     root->left = buildTree(root->left);
//     root->right = buildTree(root->right);

//     return root;
// }
// void inorder(Node* root){
//     if(root==nullptr){
//         return;
//     }

//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }
// void preorder(Node* root){
//     if(root==nullptr){
//         return;
//     }

//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }
// void postorder(Node* root){
//     if(root==nullptr){
//         return;
//     }

//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data<<" ";
// }
// void levelOrderTraversal(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(nullptr);
//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();

//         if(temp==nullptr){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(nullptr);
//             }
//         }
//         else{
//             cout<<temp->data<<" ";
//             if(temp->left){
//                 q.push(temp->left);
//             }
//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
//     }
// }
// int main() {
//     Node* root = nullptr;
//     root = buildTree(root);
//     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//     cout<<"Inorder traversal : "<<endl;
//     inorder(root);
//     cout<<"\nPreorder traversal : "<<endl;
//     preorder(root);
//     cout<<"\nPostorder traversal : "<<endl;
//     postorder(root);
//     cout<<"\nLevel Order traversal :"<<endl;
//     levelOrderTraversal(root);
//     return 0;
// }

// BUILD FROM LEVEL ORDER TRAVERSALS

// #include <bits/stdc++.h>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;
//     Node(int d)
//     {
//         this->data = d;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };
// void buildFromLOT(Node *&root)
// {
//     int data;
//     cin >> data;
//     root = new Node(data);
//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *frontNode = q.front();
//         q.pop();

//         int leftData;
//         cin >> leftData;
//         if (leftData != -1)
//         {
//             frontNode->left = new Node(leftData);
//             q.push(frontNode->left);
//         }
//         int rightData;
//         cin >> rightData;
//         if (rightData != -1)
//         {
//             frontNode->right = new Node(rightData);
//             q.push(frontNode->right);
//         }
//     }
// }
// void LOT(Node *root)
// {
//     queue<Node*> q;
//     q.push(root);
//     q.push(nullptr);
//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         if (temp == nullptr)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(nullptr);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }
// int main()
// {
//     Node* root = nullptr;
//     buildFromLOT(root);
//     LOT(root);

//     return 0;
// }

// BUILD TREE FROM ARRAY 

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
Node* arrLL(vector<int>&arr, int size){
    if(size==0) return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
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
void LOT(Node* root){
    if(root==nullptr) return ;
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
            cout<<temp->data;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="null"||str=="-1"){
            arr[i] = -1;
        }
        else{
            arr[i] = stoi(str);
        }
    }
    Node* root = arrLL(arr,n);
    LOT(root);
    return 0;
}