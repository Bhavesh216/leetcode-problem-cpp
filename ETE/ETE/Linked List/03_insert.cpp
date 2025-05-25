#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d, Node* n){
        this->data = d;
        this->next = n;
    }
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
};
Node* arrLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(Node* head){
    if(head==nullptr || head->next==nullptr){
        return;
    }
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
Node* insertHead(Node* head,int val){
    Node* newHead = new Node(val,head);
    return newHead;
}
Node* insertTail(Node*head, int val){
    Node* newTail = new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newTail;
    return head;
}
Node* insertPos(Node* head,int k,int val){
    if(head==nullptr){
        if(k==1) return new Node(val);
        else  return nullptr;
    }
    if(k==1){
        return insertHead(head,val);
    }
    Node* temp = head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            Node* newNode = new Node(val,temp->next);
            temp->next = newNode;
        }
        temp=temp->next;
    }
    return head;
}
Node* insertBefVal(Node* head, int val,int d){
    if(head==nullptr){
        return nullptr;
    }
    if(head->data == val){
        return insertHead(head,d);
    }
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->next->data==val){
            Node* newNode = new Node(d,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head = arrLL(arr);
    print(head);

    // head = insertHead(head,10);
    // print(head);

    // head = insertTail(head,100);
    // print(head);

    // head = insertPos(head,6,100);
    // print(head);

    head = insertBefVal(head, 1,100);
    print(head);
    return 0;
}