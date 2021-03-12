#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
void length(Node *h1,Node *h2,int &c1,int &c2)
{
    c1 = c2 = 0;
    while(h1 != NULL && h2 != NULL)
    {
        h1 = h1->next;
        h2 = h2->next;
        c1++;
        c2++;
    }
    while(h1 != NULL)
    {
        h1 = h1->next;
        c1++;
    }
    while(h2 != NULL)
    {
        h2 = h2->next;
        c2++;
    }
}
int intersectPoint(Node* head1, Node* head2)
{
    int l1,l2;
    length(head1,head2,l1,l2);
    int d = (l1>=l2)?((l1-l2):(l2-l1));
    int result = -1;
    int i=0;
    if(l1>=l2)
    {
        for(;i<d;i++)
        {
            if(head1 == NULL)
            {
                break;
            }
            head1 = head->next;
        }
    }
    else
    {
        for(;i<d;i++)
        {
            if(head2 == NULL)
            {
                break;
            }
            head2 = head2->next;
        }
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 == head2)
        {
            result = head1->data;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return result;
}