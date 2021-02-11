#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
	}
    return 0;
}
int digit_by_digit_compare(Node *l1,Node *l2)
{
	if(l1->next == NULL && l1->data == l2->data)
	{
		return 2;
	}
	else if(l1->next == NULL)
	{
		return (l1->data < l2->data?1:0);
	}
	else
	{
		return digit_by_digit_compare(l1->next,l2->next);
	}
}
void Bigger(Node *l1, Node *l2,int &bigger,int &c1,int &c2)
{
	c1 = c2 = 0;
	while(l1 != NULL && l2 != NULL)
	{
		c1++;
		c2++;
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1 != NULL)
	{
		c1++;
		l1 = l1->next;
	}
	while(l2 != NULL)
	{
		c2++;
		l2 = l2->next;
	}
	if(c1 > c2)
	{
		bigger = 0;
	}
	else if(c1 < c2)
	{
		bigger = 1;
	}
	else
	{
		bigger = digit_by_digit_compare(l1,l2);
	}	
}
Node* subLinkedList(Node* l1, Node* l2)
{
	int b;
	int c1,c2;
	Bigger(l1,l2,b,c1,c2);
	if(b == 2)
	{	
		cout<<"Equal condition\n";
		return l1;//new Node(0);
	}
	else
	{
		return (b==0)?l1:l2;
	}
}