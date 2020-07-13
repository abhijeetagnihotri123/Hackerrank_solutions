#include <iostream>
using namespace std;
struct  Node
{
    int data;
    Node *next;
};
Node *start,*ptr,*newptr,*save;
Node *create_new_node(int);
void insert(Node*);
void Display(Node*);
Node *reverse(Node*);
Node *addOne(Node*);
int main()
{   
    int n;
    cin>>n;
    while(n>0)
    {
        int a = n%10;
        newptr = create_new_node(a);
        insert(newptr);
        n=n/10;
    }
    start=addOne(start);
    Display(start);
    return 0;
}
Node *create_new_node(int n)
{
    ptr = new Node;
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
}
void Display(Node *np)
{
    while(np!=NULL)
    {
        cout<<np->data;
        np=np->next;
    }
}
void insert(Node *np)
{
    if(start==NULL)
    {
        start=np;
    }
    else
    {
        save=start;
        start=np;
        np->next=save;
    }
}
Node *reverse(Node*np)
{
    Node *current,*n,*prev;
    prev = NULL;
    current=np;
    while(current!=NULL)
    {
        n=current->next;
        current->next=prev;
        prev=current;
        current=n;
    }
    return prev;
}
Node *addOne(Node *head)
{
    int carry=1;
    head=reverse(head);
    Node *current=head;
    Node *aux;
    while(current!=NULL)
    {   
        int sum = (current->data+carry);
        current->data = sum%10;
        carry=sum/10;
        if(current->next==NULL)
        {
            aux = current;
        }
        current=current->next;
    }
    if(carry==1)
    {
        Node *np = new Node;
        np->data=1;
        aux->next = np;
    }
    current = head;
    head=reverse(current);
    return head;
}