//single
#include <iostream.h>

class linklist
{
	private :

		// structure containing a data part and link part
		struct node
		{
			int data ;
			node * link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		void display( ) ;
		int count( ) ;
           ~linklist( ) ;
} ;

// initializes data member
linklist :: linklist( )
{
	p = NULL ;
}

// adds a node at the end of a linked list
void linklist :: append ( int num )
{
	node *temp, *r ;

    // if the list is empty, create first node
	if ( p == NULL )
	{
		p = new node ;
		p -> data = num ;
		p -> link = NULL ;
	}
	else
	{
		// go to last node
		temp = p ;
		while ( temp -> link != NULL )
			temp = temp -> link ;

		// add node at the end
		r = new node ;
		r -> data = num ;
		r -> link = NULL ;
		temp -> link = r ;
	}
}


// displays the contents of the linked list
void linklist :: display( )
{
	node *temp = p ;

	cout << endl ;
	// traverse the entire linked list
	while ( temp != NULL )
	{
		cout << temp -> data << "  " ;
		temp = temp -> link ;
	}
}

// counts the number of nodes present in the linked list
int linklist :: count( )
{
	node *temp = p ;
	int c = 0 ;

	// traverse the entire linked list
	while ( temp != NULL )
	{
		temp = temp -> link ;
		c++ ;
	}

	return c ;
}


// deallocates memory
linklist :: ~linklist( )
{
	node *q ;

    while ( p != NULL )
    {
        q = p -> link ;
        delete p ;
    	p = q  ;
    }
}

void main( )
{
    linklist l ;

	l.append ( 14 ) ;
	l.append ( 30 ) ;
	l.append ( 25 ) ;
	l.append ( 42 ) ;
	l.append ( 17 ) ;

    cout << "\nElements in the linked list: " ;
	l.display( ) ;

	cout << "\nNo. of elements in the linked list " << l.count( ) ;
}
	