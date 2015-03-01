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
struct Node
{
	Node *next;
	int data;
};

typedef struct Node node;

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

node * createLL()
{
	node *head = (node *)malloc(sizeof(node));
	head->data = 1;
	insert(&head, 2, 2);
	insert(&head, 3, 3);
	return head;
}

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

dnode * createDLL()
{
	dnode *head = (dnode *)malloc(sizeof(dnode));
	head->data = 1;
	dInsert(&head, 2, 2);
	dInsert(&head, 3, 3);
	return head;

}

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

int main()
{
	node *newLL = createLL();
	printLL(newLL);
	dnode *newDLL = createDLL();
	printDLL(newDLL);

}