#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/*
README
double pointer to head is sent to change it in the calling fuction as well.
In all functions q is always behind p
*/

/*=============================================================================
STUFF FOR SINGLY LINKED LIST BEGINS
=============================================================================*/
// Node structure for LL
struct Node
{
	Node *next;
	int data;
};

typedef struct Node node;

// to find the length of LL
int length(node *head)
{
	node *current = head; //because otherwise we change the head pointer
	int len = 0;
	while(current != NULL)
	{
		len++;
		current = current->next;
	}
	return len;
}

// To insert a node in a singly linked list
void insert(node **head, int data, int position)
{
	node *p = *head, *q, *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	if (position ==1) //head position
	{
		newNode->next = p;
		*head = newNode;
	}
	else 
	{
		int k=1;// to count the positions
		while (k<position && p!=NULL)
		{	
			k++;
			q = p;
			p = p->next;
		}
			q->next = newNode;
			newNode->next = p;	
	}

}

// to delete a node in a singly linked list
void deleteNode(node **head, int position)
{
	int k =1;
	node *p,*q;
	p = *head;
	if(position == 1)
	{
		*head = (*head)->next;
		free(p);
	}
	else
	{
		while(k<position && p!=NULL)
		{
			k++;
			q = p;
			p = p->next;
		}
		q->next = p->next;
		free(p);
	}
}

// delete the whole linked list
void deleteList(node **head)
{
	node *p = *head,*q;
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

// Create a dummy LL 1->2->3
node * createLL()
{
	node *head = (node *)malloc(sizeof(node));
	head->data = 1;
	insert(&head, 2, 2);
	insert(&head, 3, 3);
	insert(&head, 4, 4);
	insert(&head, 5, 5);
	insert(&head, 6, 6);
	insert(&head, 7, 7);
	
	return head;
}

// Create Cyclic LL
node * createCyclicLL()
{
	node *head = (node *)malloc(sizeof(node));
	node *head2 = (node *)malloc(sizeof(node));
	head2->data = 8;
	head->data = 1;
	insert(&head, 2, 2);
	insert(&head, 3, 3);
	insert(&head, 4, 4);
	insert(&head, 5, 5);
	insert(&head, 6, 6);
	insert(&head, 7, 7);

	insert(&head2, 9, 2);
	insert(&head2, 10, 3);
	head->next->next->next->next->next->next->next = head2;
	head2->next->next->next = head->next->next;
	return head;
}

// Print the LL starting at head
void printLL(node *head)
{
	if(head != NULL)
		cout<<head->data;
	node *p = head->next;

	while(p != NULL)
	{
		cout<<"->"<< p->data;
		p = p->next;
	}
	cout<<endl;
}
/*=============================================================================
STUFF FOR SINGLY LINKED LIST ENDS
=============================================================================*/

/*=============================================================================
STUFF FOR DOUBLY LINKED LIST BEGINS
=============================================================================*/
// Structure for the node of a DLL
struct Dnode{
	struct Dnode *next, *previous;
	int data;
};

typedef struct Dnode dnode;
// Length can be implemented in the exact same way as SLL

// to insert a node at a specified position in a doubly linked list
void dInsert(dnode **head, int data, int position)
{
	dnode *p,*newNode;
	newNode = (dnode *) malloc(sizeof(dnode));
	newNode->data = data;
	p = *head;
	if(position==1)
	{
		newNode->previous = NULL;
		newNode->next = *head;
		(*head)->previous = newNode;
		*head = newNode;
	}
	else
	{
		int k = 1;
		while(k<position-1 && p!=NULL)
		{
			k++;
			p = p->next;
		}
		newNode->next = p->next;
		newNode->previous = p;

		// when p is last then p->next may be NULL->previous, hence error
		if (p->next) 
			p->next->previous = newNode;
		p->next = newNode;
	}
}


void dDeleteNode(dnode **head, int position)
{
	dnode *p=*head;
	int k = 1;
	if (position==1)
	{
		p->next->previous = NULL;
		*head = p->next;
		free(p);
	}
	while(k<position)
	{
		k++;
		p = p->next;
	}
	p->previous->next = p->next;
	if (p->next)
		p->next->previous = p->previous;
	free(p);
}

// delete the whole DLL
void dDeleteList(dnode **head)
{
	dnode *p = *head, *q;
	while(p!=0)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

// Create a dummy DLL 1<->2<->3
dnode * createDLL()
{
	dnode *head = (dnode *)malloc(sizeof(dnode));
	head->data = 1;
	dInsert(&head, 2, 2);
	dInsert(&head, 3, 3);
	return head;

}

// Print the DLL starting at head
void printDLL(dnode *head)
{
	dnode *p = head->next;
	cout<<head->data;
	while(p!=NULL)
	{
		cout<<"<->"<<p->data;
		p = p->next;
	}
	cout<<endl;
}

/*=============================================================================
STUFF FOR DOUBLY LINKED LIST ENDS
=============================================================================*/

/*=============================================================================
LINKED LISTS PROBLEMS
=============================================================================*/
// Returns the nth node from the end and print its data
node * nthFromEnd(node *head, int n)
{
	node *a = head,*b = head;
	int k = 0;
	while (a->next!=NULL)
	{
		k++;
		a = a->next;
		if (k>=n)
			b = b->next;
	}
	cout<< b->data <<endl;
	return b;
}

// Cycle Detection Floyd Algorithm
int hasCycle(node * head)
{
	node *slow, *fast;
	slow = head;
	fast = head;
	while(slow && fast && fast->next)
	{
		slow = slow->next;;
		fast = fast->next->next;
		if (slow == fast) //collision
			return 1; // cycle exists 
	}
	return 0;
}

// Find the starting node of the cycle and the length of the cycyle
node * cycleStart(node * head)
{
	node *slow, *fast;
	slow = head;
	fast = head;
	int cyclePresent = 0, cycyleLength =0;
	while(slow && fast && fast->next)
	{
		slow = slow->next;;
		fast = fast->next->next;
		if (slow == fast) //collision
			{
				cyclePresent = 1;
				break;
			}

	}
	if (cyclePresent)
	{
		fast = head;
		while(slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
			cycyleLength++;
		}
		cout << fast->data <<endl;
		cout << "length =" <<cycyleLength; 
		return fast;

	}
	return NULL;
}

// Reverse a SLL

node * reverse(node * head)
{
	node *temp = NULL, *nextNode=head->next;
	while(nextNode != NULL)
	{	
		nextNode = head->next;
		head->next = temp;
		temp = head;
		head = nextNode;
	}
	return temp; // dont return head or next as it might be NULL
}



/*=============================================================================
LINKED LISTS PROBLEMS END
=============================================================================*/


int main()
{
	node *newLL = createLL();
	printLL(newLL);
	
	/*
	dnode *newDLL = createDLL();
	printDLL(newDLL);
	*/
	
	//nthFromEnd(newLL , 5);
	
	node *cycLL = createCyclicLL();
	//printLL(cycLL); // goes in a infinite loop as expected
	//cout<<hasCycle(cycLL);
	//cout<<hasCycle(newLL);
	//cycleStart(cycLL);

	//node *revLL = reverse(newLL);
	
	printLL(revLL);

}
