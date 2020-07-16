#include <iostream>
using namespace std;
struct  Node
{
    int data;
    Node *next;
};
Node *start,*ptr,*newptr,*save,*rear;
Node *create_new_node(int);
void insert(Node*);
void Display(Node*);
Node *reverse(Node*);
Node *rotate(Node*,int);
int length(Node*);
int main()
{   
    int T,n,k,r;
    cin>>T;
    while(T--)
    {
        start=rear=NULL;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            newptr = create_new_node(k);
            insert(newptr);
        }
        cin>>r;
        start = rotate(start,r);
        Display(start);
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
void insert(Node *np)
{
    if(start==NULL)
    {
        start=rear=np;
    }
    else
    {
        rear->next = np;
        rear = np;
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
int length(Node *head)
{
    int c = 0;
    while(head!=NULL)
    {
        head=head->next;
        c++;
    }
    return c;
}
Node *rotate(Node *head,int k)
{
    Node *current = NULL;
    Node *head1 = head;
    int n = length(head);
    //cout<<n<<endl;
    k = k%n;
    while(k>1)
    {   
        if(head != NULL)
        {
           head = head->next;
        }
        else
        {
            break;
        }
        k--;
    }
    current = head->next;
    head->next = NULL;
    head = current;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = head1;
    return head;
}