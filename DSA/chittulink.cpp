#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *back;

    public:
    node(int data1, node* next1, node *back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

node *arr2doublyLL(vector<int>&arr){
    node *head = new node(arr[0]);
    node *prev = head;

    for(int i = 1; i< arr.size(); i++){
        node *temp = new node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

node *RemoveHead(node *head){
    if(head == NULL) return head;

    if(head -> next == nullptr){
        delete head;
        return 0;
    }

    node *temp = head -> next;

    temp -> back = nullptr;
    delete head;
    return temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    node *head = arr2doublyLL(arr);
    

    head = RemoveHead(head);
    node *temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}