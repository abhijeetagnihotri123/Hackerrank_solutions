#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *start[2],*newptr,*ptr,*save;
Node *Create_new_node(int);
void insert_digit(Node *,int);
void insert_number(int,int);
void display(Node*);
Node* reverse(Node*);
Node *subtraction(Node*,Node*);
void length(Node*,Node*,int&,int&);
bool first_number_bigger(Node*,Node*,int,bool &);
void pad_zero(Node *,int);
int main()
{   
    start[0]=start[1]=NULL;
    char ch='y';
    int n1,n2;
    cin>>n1>>n2;
    insert_number(n1,0);
    insert_number(n2,1);
    subtraction(start[0],start[1]);
    return 0;
}
Node *Create_new_node(int n)
{
    ptr=new Node;
    ptr->data=n;
    ptr->next=NULL;
    return ptr;
}
void insert_number(int n,int index)
{
    while(n>0)
    {
        int a = n%10;
        ptr = Create_new_node(a);
        insert_digit(ptr,index);
        n = n/10;
    }
}
void insert_digit(Node *np,int index)
{
    if(start[index] == NULL)
    {
        start[index]=np;
    }
    else
    {
        save = start[index];
        start[index]=np;
        start[index]->next = save;
    }
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
Node* reverse(Node *head)
{
    Node *current;
    Node *prev=NULL;
    Node *n;
    current = head;
    while(current!=NULL)
    {
        n = current->next;
        current->next=prev;
        prev = current;
        current = n;
    }
    return prev;
}
void length(Node *head1,Node *head2,int &n1,int &n2)
{   
    n1=0;
    n2=0;
    while(head1!=NULL && head2!=NULL)
    {
        head1=head1->next;
        head2=head2->next;
        n1++;
        n2++;
    }
    while(head1!=NULL)
    {
        head1=head1->next;
        n1++;
    }
    while(head2!=NULL)
    {
        head2=head2->next;
        n2++;
    }
}
Node *subtraction(Node *head1,Node *head2)
{
    int c1,c2;
    length(head1,head2,c1,c2);
    Node *result = NULL;
    if(c1>c2)
    {
        head1=reverse(head1);
        head2=reverse(head2);
        int c = 0;
        while()
    }
    else if(c1==c2)
    {
        bool flag,equal;
        flag = first_number_bigger(head1,head2,c1,equal);
        if(equal)
        {   
            int x = 0;
            Node *result = new Node(x);
            return 
        }
        else if(flag)
        {
            cout<<"First NUmber bigger"<<endl;
        }
        else
        {
            cout<<"second number bigger"<<endl;
        }
        
    }
    else
    {
        cout<<"Second number is bigger"<<endl;
    }
    return result;   
}
bool first_number_bigger(Node *head1,Node *head2,int length,bool &equal)
{   
    bool result;
    int c = 0;
    while(head1!=NULL)
    {
        if(head1->data > head2->data)
        {
            result=true;
            equal=false;
            break;
        }
        else if(head1->data == head2->data)
        {   
            head1=head1->next;
            head2=head2->next;
            c++;
        }
        else
        {
            result = false;
            break;
        }
    }
    if(c == length)
    {   
        result=false;
        equal=true;
    }
    return result;
}//try tomorrow
