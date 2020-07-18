#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
	int data;
	struct Node* npx;
};

struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node* insert(struct Node* head, int data);

void printList (struct Node *head);

int main ()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        struct Node *head = NULL;
        int n, tmp;
        
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &tmp);
            head = insert(head, tmp);
        }
        printList (head);
        printf("\n");
    }
	return (0);
}
struct Node* insert(struct Node *head, int data)
{
	if(head == NULL)
	{
	    head = new Node;
	    head->data = data;
	    head->npx = NULL;
	}
	else
	{
	    Node *newptr,*n1,*n2;
	    n1 = NULL;
	    n2 = head->npx;
	    newptr = new Node;
	    newptr->data = data;
	    head->npx = XOR(n2,newptr);
	    newptr->npx = XOR(head,n1);
	    head = newptr;
	    return head;
	}
}

// function should prints the contents of doubly linked list
// first in forward direction and then in backward direction
// you should print a next line after printing in forward direction
void printList (struct Node *head)
{   
    Node *p = NULL;
	Node *n;
	Node *current = head;
	while(current!= NULL)
	{
	    n = XOR(current->npx,p);
	    p = current;
	    cout<<current->data<<" ";
	    current = n;
	}
	cout<<endl;
	current = p;
	p = NULL;
	while(current != NULL)
	{
	    n = XOR(current->npx,p);
	    p = current;
	    cout<<current->data<<" ";
	    current = n;
	}
	cout<<endl;
}
