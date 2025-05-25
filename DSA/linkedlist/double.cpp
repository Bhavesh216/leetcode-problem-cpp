#include<iostream>
using namespace std;

class linklist{
    private:
    struct node{
        int data;
        node * next;
        node * prev;
    }*head,*mov,*tail;
    
    public:
    linklist() ;
    void d_append ( int num ) ;
	void d_addatbeg ( int num ) ;
	void d_addafter ( int loc, int num ) ;
	void d_display( ) ;
	int d_count( ) ;
	void d_delete( int i ) ;
};
// initializes data member
linklist::linklist(){
    head=NULL;
   // tail=NULL;
   // mov=NULL;
}

// adds a new node at the end of the doubly linked list
void linklist::d_append(int num){
    mov=head;
    // if the linked list is empty
    if(mov==NULL)
    {
        //create a new node
        mov= new node;
        mov->prev=NULL;
        mov->data=num;
        mov->next=NULL;
        head=mov;
    }
    else
    {
      while(mov->next !=NULL)  
      {
        mov=mov->next;
        tail= new node;
        tail->data=num;
        tail->next=NULL;
        tail->prev=

      }
    }
}

Node *head,*mov,*tail;
mov=head;
while(mov-next!=NULL){
    mov->next=mov->prev;
    mov->prev=mov->next;
    mov=mov->next;
}

