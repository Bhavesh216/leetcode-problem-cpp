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
vector<vector<int>> zigzag(Node*root){
    vector<vector<int>> res;
    if(root == nullptr) return res;
    queue<Node*> q;
    q.push(root);
    bool l2r = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            int ind = (l2r)?i:n-i-1;
            ans[ind] = temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        l2r =!l2r;
        res.push_back(ans);
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str == "null" || str =="-1"){
            arr[i]=-1;
        }
        else{
            arr[i] = stoi(str);
        }
    }
    Node* root = arrLL(arr,n);
    vector<vector<int>> zz = zigzag(root);
    for(auto i : zz){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}