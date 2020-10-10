#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        
        Node *sum = addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;  
    }
}
void insert(Node *L,int coeff,int power)
{
    Node *ptr = new Node(coeff,power);
    if(L->next == NULL)
    {
        L->next = ptr;
        ptr->next = L;
    }
    else
    {
        Node *start = L;
        L->pow = power-1;
        while(start->next->pow < power)
        {   
            start = start->next;
        }
        L->pow = -1;
        ptr->next = start->next;
        start->next = ptr;
    }
}
Node * addPolynomial(Node *start1, Node *start2)
{
    Node *L = new Node(-1,-1);
    int coeff,exponent;
    while(start1 != NULL && start2 != NULL)
    {
        if(start1->pow > start2->pow)
        {
            coeff = start1->coeff;
            exponent = start1->pow;
            insert(L,coeff,exponent);
            start1 = start1->next;
        }
        else if(start1->pow < start2->pow)
        {
            coeff = start2->coeff;
            exponent = start2->pow;
            insert(L,coeff,exponent);
            start2 = start2->next;
        }
        else
        {
            coeff = start1->coeff + start2->coeff;
            if(coeff != 0)
            {
                exponent = start1->pow;
                insert(L,coeff,exponent);
            }
            start1 = start1->next;
            start2 = start2->next;   
        }
    }
    while(start1 != NULL)
    {
        coeff = start1->coeff;
        exponent = start1->pow;
        insert(L,coeff,exponent);
        start1 = start1->next;
    }
    while(start2 != NULL)
    {
        coeff = start2->coeff;
        exponent = start2->pow;
        insert(L,coeff,exponent);
        start2 = start2->next;
    }
    Node *head = L->next;
    delete(L);
    return head;
}