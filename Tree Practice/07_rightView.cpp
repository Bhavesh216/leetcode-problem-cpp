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
Node* arrTree(vector<int>&arr, int size){
    if(size==0) return nullptr;
    queue<Node*> q;
    Node* root = new Node(arr[0]);
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
vector<vector<int>> LOT(Node* root){
    vector<vector<int>> ans;
    if(root==nullptr){
    return ans;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            level[i] = temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}
vector<int> rightView(Node* &root){
    vector<int> ansRight;
    vector<vector<int>> right = LOT(root);
    for(auto i : right){
        ansRight.push_back(i.back());
    }
    return ansRight;
}
int main() {
    int n;
    cin>>n;
    string str;
    vector<int>arr(n);
    vector<int> ans; 
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="null"||str=="-1"){
            arr[i] = -1;
        }
        else{
            arr[i] = stoi(str);
        }
    }
    Node* root = arrTree(arr,n);
    vector<int> left = rightView(root);
    for(auto i: left){
        cout<<i<<" ";
    }

    return 0;
}