#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *arrTree(vector<int> &arr, int size)
{
    if (size == 0)
        return nullptr;
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (i < size && !q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if (arr[i] != -1 && i < size)
        {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
bool isLeaf(Node *root)
{
    if (root == nullptr)
    {
        return false;
    }
    return (root->left == nullptr && root->right == nullptr);
}
void addLeft(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);

        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void addRight(Node* root,vector<int>&res){
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
void addLeaves(Node* root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}
vector<int> boundary(Node* root){
    vector<int> res;
    if(root==nullptr) return res;
    if(!isLeaf(root)) res.push_back(root->data);

    addLeft(root,res);
    addLeaves(root,res);
    addRight(root,res);

    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    string str;
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
    vector<int> bou = boundary(root);
    for(auto i: bou){
        cout<<i<<" ";
    }

    return 0;
}