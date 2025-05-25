#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

node* buildtree(node* root){
    cout<<"enter the data";
    int data;
    cin>>data;
    root=new node(data);
    
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting at right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void buildlevelordee(node *&root){

queue<node*> q;
cout<<"\n enter data";
int data;
cin>>data;
root=new node(data);
q.push(root);

while(!q.empty()){

    node*temp=q.front();
    q.pop();

    cout<<"\n enter element at left of"<<temp->data;
    int leftdata;
    cin>>leftdata;

    if(leftdata!=-1){
        temp->left=new node(leftdata);
        q.push(temp->left);
    }

    cout<<"\n enter data at right of "<<temp->data;
    int rightdata;
    cin>>rightdata;

    if(rightdata!=-1){
        temp->right=new node(rightdata);
        q.push(temp->right);
    }
 }
}

void levelorder(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
    node* temp=q.front();
    cout<<temp->data<<" ";
    q.pop();

    if(temp->left){
        q.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
    }
  }
}



void inorder(node *root){  
if(root == NULL){
    return ;
}
    
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;

    }    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);

}

int height(node* root){
    if(root==NULL){
        return 0 ;
    }
    else{
    int  left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
    }
}

int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int left=diameter(root->left);
    int right=diameter(root->right);
    int h=height(root->left)+height(root->right)+1

    int ans=max(left,right,h);
    return ans;
}

bool checkbalanace(node *root){
    if(root==NULL){
        return true;
    }
    bool left=checkbalanace(root->left);
    bool right=checkbalanace(root->right);
    bool ans= abs (height(left)-height(right))<=1;

    if(left&&right&&ans){
        return 1;

    }
    else{
        return false;
    }
}

bool identical(node* r1,node* r2){
    if(r1==NULL&& r2==NULL){
        return true;
    }
    if(r1==NULL&&r2!=NULL){
        return false;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }
   
    bool left=identical(r1->left,r2->left);
    bool right=identical(r1->right,r2->right);
    bool val=r1->data==r2->data;
    
    if(left&&right&&val){
        return 1;
    }
    else{
        return false;
    }
}


int main(){
    node* root=NULL;
    buildlevelordee(root);
    int h=height(root);
    cout<<"\n height"<<h;

    // cout<<"\ninorder ";
    // inorder(root);
    // cout<<"\npostorder";
    // postorder(root);
    // cout<<"\npreorder";
    // preorder(root);
    // cout<<"\nlevelorder";
    // levelorder(root);

    return 0;
}