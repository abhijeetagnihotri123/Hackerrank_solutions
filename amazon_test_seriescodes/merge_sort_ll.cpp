#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *newptr,*ptr,*start,*rear;

Node *create_new_node(int n)
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
void display(Node *np)
{
    Node *aux;
    while(np != NULL)
    {
        cout<<np->data<<" ";
        aux = np;
        np = np->next;
        delete(aux);
    }
    cout<<endl;
}
void merge(Node *head,int l,int m,int r)
{
    Node *B,*R1,*C,*R2,*current;
    B = C = R1 = R2 = NULL;
    int n1 = m-l+1;
    int n2 = r-m;
    current = head;
    for(int i=0;i<n1;i++)
    {   
        newptr = create_new_node(head->data);
        if(B == NULL)
        {
            B = R1 = newptr;
        }
        else
        {
            R1->next = newptr;
            R1 = newptr;
        }
        head = head->next;
    }
    for(int i=0;i<n2;i++)
    {   
        newptr = create_new_node(head->data);
        if(C == NULL)
        {
            C = R2 = newptr;
        }
        else
        {
            R2->next = newptr;
            R2 = newptr;
        }
        head = head->next;
    }
    head = current;
    while(B != NULL && C != NULL)
    {
        if(B->data <= C->data)
        {
            head->data = B->data;
            newptr = B;
            B = B->next;
            delete(newptr);
        }
        else //if(C->data <= B->data)
        {
            head->data = C->data;
            newptr = C;
            C = C->next;
            delete(newptr);
        }
        head = head->next;
    }
    while(B != NULL)
    {
        head->data = B->data;
        newptr = B;
        B = B->next;
        head = head->next;
        delete(newptr);
    }
    while(C != NULL)
    {
        head->data = C->data;
        newptr = C;
        C = C->next;
        head = head->next;
        delete(newptr);
    }
}
void MergeSort(Node *head,int l,int r)
{
    if(l<r)
    {
        int m = (l+r);
        m = (m>>1);
        //MergeSort(head,l,m);
        //MergeSort(head,m+1,r);
        merge(head,l,m,r);
    }
}
Node *mergeSort(Node *head, int l,int r)
{   
    MergeSort(head,0,r);
    return head;
}
int main()
{   
    start = rear = NULL;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        newptr = create_new_node(k);
        insert(newptr);
    }
    start = mergeSort(start,0,n-1);
    display(start);
    return 0;
}