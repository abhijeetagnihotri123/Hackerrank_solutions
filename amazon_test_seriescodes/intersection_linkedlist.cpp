#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newptr,*ptr,*start[2],*rear[2];

Node *create_new_node(int);
void insert_rear(Node*,int);
void display(Node*);
Node *findIntersection(Node*,Node*);
int main()
{
    int n,m;
    cin>>n>>m;
    start[0] = rear[0] = start[1] = rear[1] = NULL;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        newptr = create_new_node(k);
        insert_rear(start[0],0);
    }
    for(int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        newptr = create_new_node(k);
        insert_rear(start[1],1);
    }
    Node *head = findIntersection(start[0],start[1]);
    display(head);
}
Node *findIntersection(Node *head1,Node *head2)
{
    map<int,bool>m;
    Node *current,*rear1;
    current = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        if(head2->data < head1->data)
        {
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
            cout<<head1->data<<" ";   
        }
    }
    return NULL;
}
Node *create_new_node(int n)
{
    ptr = new Node;
    ptr->data = n;
    ptr->next = NULL;
    return ptr;
}
void insert_rear(Node *np,int index)
{
    if(start[index] == NULL)
    {
        start[index] = rear[index] = np;
    }
    else
    {
        rear[index]->next = np;
        rear[index] = np;
    }
}
void display(Node *np)
{
    while(np != NULL)
    {   
        cout<<np->data<<" ";
        np = np->next;
    }
    cout<<endl;
} 