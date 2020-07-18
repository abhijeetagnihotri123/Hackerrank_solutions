#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// Rearranges given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head);

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }

        head = rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
Node *rearrangeEvenOdd(Node *head)
{   
    Node *current1 = head;
    Node *current2 = head->next;
    int a[1001];
    int n=0;
    while(current1 != NULL)
    {
        if(current1->next == NULL)
        {
            break;
        }
        a[n++]=(current1->data);
        current1 = current1->next->next;
    }
    while(current2 != NULL)
    {   
        if(current2->next == NULL)
        {
            break;
        }
        a[n++]=(current2->data);
        current2 = current2->next->next;
    }
    current1 = head;
    int i;
    for(i=0;i<n;i++)
    {
        current1->data = a[i];
        current1 = current1->next;
    }
    return head;
}