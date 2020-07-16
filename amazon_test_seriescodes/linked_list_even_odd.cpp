#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newptr,*ptr,*start,*rear;

Node *create_new_node(int);
void insert_rear(Node*);
void display(Node*);
Node *rearrangeEvenOdd(Node*);
int main()
{
    int n;
    cin>>n;
    start = rear = NULL;
    for(int i=1;i<=n;i++)
    {
        newptr = create_new_node(i);
        insert(newptr);
    }
    start = rearrangeEvenOdd(start);
}
Node *rearrangeEvenOdd(Node *head)
{
    Node *current1,*current2,*backup1,*backup2;
    current1 = backup1 = head;
    current2 = backup2 = head->next;
    while(current1 != NULL && current2 != NULL)
    {
        current1->next = current1->next->next;
        current2->next = current2->next->next;
        if(current1->next == NULL || current2->next == NULL)
        {
            break;
        }
        else
        {
            current1 = current1->next;
            current2 = current2->next;
        }
    }
}
Node *create_new_node(int n)
{
    ptr = new Node;
    ptr->data = n;
    ptr->next = NULL;
    return ptr;
}
void insert_rear(Node *np)
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
void display(Node *np)
{
    while(np != NULL)
    {   
        cout<<np->data<<" ";
        np = np->next;
    }
    cout<<endl;
} 