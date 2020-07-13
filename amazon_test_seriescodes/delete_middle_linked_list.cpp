#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *newptr,*start,*rear,*ptr;

Node *Create_new_Node(int&);
void insert(Node *);
void Display(Node *);
Node *delete_middle(Node *);
int main()
{   
    int n;
    cin>>n;
    start = rear = NULL;
    for(int i=1;i<=n;i++)
    {
        newptr = Create_new_Node(i);
        insert(newptr);
    }
    start = delete_middle(start);
    Display(start);
    return 0;
}

Node *Create_new_Node(int &n)
{
    ptr = new Node;
    ptr->data = n;
    ptr->next = NULL;
    return ptr;
}

void insert(Node *np)
{
    if(start == NULL)
    {
        start = rear = np;
    }
    else
    {
        rear->next = np;
        rear = np;
    }
}

void Display(Node *np)
{
    while(np!=NULL)
    {
        cout<<np->data<<" ";
        np = np->next;
    }
    cout<<endl;
}

Node *delete_middle(Node *head)
{
    Node *first = head;
    Node *second = head->next->next;
    while(second->next != NULL)
    {   
        if(second->next->next == NULL)
        {
            first = first->next;
            break;
        }
        else
        {
            second = second->next->next;
            first = first->next;   
        }
    }
    Node *save = first->next;
    first->next = save->next;
    delete(save);
    return head;
}