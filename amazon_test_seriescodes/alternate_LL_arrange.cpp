#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */

void rearrange(struct Node *odd);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        rearrange(start);
        printList(start);
    }
    return 0;
}
Node* reverse(struct Node *head)
{
    Node *current,*n,*prev;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    return prev;
}
void rearrange(struct Node *head)
{
    if(head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return;
    }
    else if(head->next->next->next == NULL)
    {
        Node *n = head->next;
        head->next = head->next->next;
        head->next->next = n;
        n->next = NULL;
    }
    else
    {
        struct Node *h1,*h2,*s1,*s2;
        s1 = h1 = head;
        s2 = h2 = head->next;
        while(h1->next->next != NULL && h2->next->next != NULL)
        {
            h1->next = h1->next->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        if(h1->next != NULL)
        {
            h2 = s2;
            h2 = reverse(h2);
            h1->next = h2;   
        }
        else
        {
            h2->next = NULL;
            h2 = reverse(s2);
            h1->next = h2;
        }
    }
}
