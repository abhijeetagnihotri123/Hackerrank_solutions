#include <iostream>
using namespace std;
struct  Node
{
    int data;
    Node *next;
};
Node *start[2],*ptr,*newptr,*save,*rear[2];
Node *create_new_node(int);
void insert(Node*,int);
void Display(Node*);
Node *sortedMerge(Node*,Node*);
int main()
{   
    int T,n,m,k;
    cin>>T;
    while(T--)
    {
        start[0]=rear[0]=start[1]=rear[1]=NULL;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            newptr = create_new_node(k);
            insert(newptr,0);
        }
        for(int i=0;i<m;i++)
        {
            cin>>k;
            newptr = create_new_node(k);
            insert(newptr,1);
        }
        Node *head = NULL;
        head = sortedMerge(start[0],start[1]);
        Display(head);
    }
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
        cout<<np->data<<" ";
        np=np->next;
    }
    cout<<endl;
}
void insert(Node *np,int index)
{
    if(start[index]==NULL)
    {
        start[index]=rear[index]=np;
    }
    else
    {
        rear[index]->next = np;
        rear[index] = np;
    }
}
Node *sortedMerge(Node *head1,Node *head2)
{
    Node *current,*rear1;
    current = rear1 = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            ptr = create_new_node(head1->data);
            if(current == NULL)
            {
                current=rear1=ptr;
            }
            else
            {
                rear1->next = ptr;
                rear1 = ptr;    
            }
            //Node *current1 = head1;
            head1 = head1->next;
            //delete(current1);
        }
        if(head2->data <= head1->data)
        {
            ptr = create_new_node(head2->data);
            if(current == NULL)
            {
                current=rear1=ptr;
            }
            else
            {
                rear1->next = ptr;
                rear1 = ptr;
            }
            //Node *current2 = head2;
            head2 = head2->next;
            //delete(current2);
        }
    }
    while(head1 != NULL)
    {
        ptr = create_new_node(head1->data);
        if(current == NULL)
        {
            current=rear1=ptr;
        }
        else
        {
            rear1->next = ptr;
            rear1 = ptr;    
        }
        //Node *current1 = head1;
        head1 = head1->next;
        //current1->next = NULL;
        //delete(current1); 
    } 
    while(head2 != NULL)
    {
        ptr = create_new_node(head2->data);
        if(current == NULL)
        {
            current=rear1=ptr;
        }
        else
        {
            rear1->next = ptr;
            rear1 = ptr;    
        }
        //Node *current2 = head1;
        head2 = head2->next;
        //current2->next = NULL;
        delete(current2);
    }
    return current;
}