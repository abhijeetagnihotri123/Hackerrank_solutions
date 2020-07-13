#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *start[2],*save,*newptr,*ptr;
Node *create_new_node(int);
void display(Node*);
void insert(Node*,int);
Node *reverse(Node*);
void length(Node *,Node*,int&,int&);
//void pad_zero(Node*,int);
Node *addTwoLists(Node*,Node*);
int main()
{   
    start[0]=start[1]=NULL;
    int n;
    cin>>n;
    while(n>0)
    {
        int a = n%10;
        newptr = create_new_node(a);
        insert(newptr,0);
        n=n/10;
    }
    cin>>n;
    while(n>0)
    {
        int a = n%10;
        newptr = create_new_node(a);
        insert(newptr,1);
        n=n/10;
    }
    display(addTwoLists(start[0],start[1]));
    
    return 0;
}
Node *create_new_node(int n)
{
    ptr=new Node;
    ptr->data=n;
    ptr->next=NULL;
    return ptr;
}
void display(Node *np)
{
    while(np!=NULL)
    {
        cout<<np->data;
        np=np->next;
    }
    cout<<endl;
}
void insert(Node *np,int index)
{
    if(start[index]==NULL)
    {
        start[index]=np;
    }
    else
    {
        save=start[index];
        start[index]=np;
        np->next=save;
    }
}
Node *reverse(Node *head)
{
    Node *current,*n,*prev;
    prev = NULL;
    current = head;
    while (current!=NULL)
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    return prev;
}
void length(Node *head1,Node *head2,int &n,int &m)
{
    n=m=0;
    while(head1!=NULL && head2!=NULL)
    {
        head1=head1->next;
        head2=head2->next;
        n++;
        m++;
    }
    while(head1!=NULL)
    {
        head1=head1->next;
        n++;
    }
    while(head2!=NULL)
    {
        head2=head2->next;
        m++;
    }
}
Node *addTwoLists(Node *head1,Node *head2)
{
    int n,m;
    length(head1,head2,n,m);
    Node *result=NULL;
    Node *current1 = reverse(head1);
    Node *current2 = reverse(head2);
    head1 = current1;
    head2 = current2;
    int carry=0;
    if(n>m)
    {   
        Node *aux;
        while(current2!=NULL)
        {
            int sum = (current1->data+current2->data+carry);
            current1->data = sum%10;
            carry = sum/10;
            current1=current1->next;
            current2=current2->next;
        }
        while(current1!=NULL)
        {
            int sum = (current1->data+carry);
            current1->data = sum%10;
            carry=sum/10;
            if(current1->next == NULL)
            {
                aux = current1;
            }
            current1=current1->next;
        }
        if(carry>0)
        {
            newptr = create_new_node(carry);
            aux->next=newptr;
            aux = newptr;
            result = reverse(head1);
        }
        else
        {
            result = reverse(head1);   
        }
    }
    else if(n==m)
    {   
        Node *aux;
        while(current1 != NULL)
        {   
            int sum = (current1->data+current2->data+carry);
            current1->data = sum%10;
            carry = sum/10;
            if(current1->next == NULL)
            {
                aux = current1;
            }
            current1=current1->next;
            current2=current2->next;
        }
        if(carry>0)
        {
            newptr = create_new_node(carry);
            aux->next = newptr;
            aux = newptr;
            result = reverse(head1);
        }
        else
        {
            result = reverse(head1);
        }
    }
    else
    {
        Node *aux;
        while(current1!=NULL)
        {
            int sum = (current1->data+current2->data+carry);
            current2->data = sum%10;
            carry = sum/10;
            current1=current1->next;
            current2=current2->next;
        }
        while(current2!=NULL)
        {
            int sum = (current2->data+carry);
            current2->data = sum%10;
            carry=sum/10;
            if(current2->next == NULL)
            {
                aux = current2;
            }
            current2=current2->next;
        }
        if(carry>0)
        {
            newptr = create_new_node(carry);
            aux->next=newptr;
            aux = newptr;
            result = reverse(head2);
        }
        else
        {
            result = reverse(head2);   
        }
    }
    return result;
}
