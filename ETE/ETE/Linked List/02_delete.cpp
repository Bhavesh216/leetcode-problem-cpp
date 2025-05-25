#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d,Node* n){
        this->data = d;
        this->next = n;
    }
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
};
Node* arrLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }   
    return head;
}
void print(Node* &head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
Node* deleteHead(Node* head){
    if(head == nullptr || head->next==nullptr) return nullptr;

    Node* delHead = head;
    head = head->next;
    delete delHead;
    return head;
}
Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;

    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* delTail = temp->next;
    temp->next = nullptr;
    delete delTail;
    return head;
}
Node* delKpos(Node* head,int k){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    if(k==1){
        return deleteHead(head);
    }
    int cnt=0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt==k-1){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
        temp=temp->next;
    }
    return head;
}
Node* deleteVal(Node* head, int val){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    Node* temp = head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->next->data==val){
            Node* delNode = temp->next;
            temp->next=temp->next->next;
            delete delNode;
        }
        temp=temp->next;
    }
    return head;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* head = arrLL(arr);
    print(head);
    // head = deleteHead(head);
    // print(head);
    
    // head = deleteTail(head);
    // print(head);

    // head = delKpos(head,3);
    // print(head);

    head = deleteVal(head,4);
    print(head);
    return 0;
}