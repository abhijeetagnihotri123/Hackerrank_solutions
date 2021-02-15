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
Node* addPolynomial(Node *p1, Node *p2)
{   
    Node *s1,*s2,*n1,*n2,*tmp,*save,*L;
    if(p1->pow >= p2->pow)
    {
        s1 = p1;
        s2 = p2;
    }
    else
    {
        s1 = p2;
        s2 = p1;
    }
    L = new Node(0,0);
    save = L;
    L->next = s1;
    while(L->next != NULL && s2 != NULL)
    {
        if(L->next->pow == s2->pow)
        {
            L->next->coeff += s2->coeff;
            tmp = s2;
            s2 = s2->next;
            L = L->next;
            delete(tmp);
        }
        else if(L->next->pow > s2->pow)
        {
            L = L->next;
        }
        else
        {
            n1 = L->next;
            L->next = s2;
            n2 = s2->next;
            s2->next = n1;
            L = s2;
            s2 = n2; 
        }
    }
    if(s2 != NULL)
    {
        L->next = s2;
    }
    L = save;
    delete(L);
    return s1;
}

