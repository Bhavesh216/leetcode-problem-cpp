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
Node* arrLL(vector<int> &arr,int size){
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
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
int main() {
    int n;
    cin>>n;
    string str;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="null" ||str =="-1"){
            arr[i]=-1;
        }
        else{
            arr[i]=stoi(str);
        }
    }
    Node* root = arrLL(arr,n);
    LOT(root);
    
    return 0;
}