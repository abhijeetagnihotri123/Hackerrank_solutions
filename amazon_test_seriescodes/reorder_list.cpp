#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *n = NULL;
    Node *current=head;
    while(current != NULL)
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    return prev;
}
void reorderList(Node* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL)
    {
        // do nothing
    }
    else if(head->next->next->next == NULL)
    {
        Node *ptr = head->next;
        head->next = ptr->next;
        head->next->next = ptr;
        ptr->next = NULL;
    }
    else if(head->next->next->next->next == NULL)
    {
        Node *ptr = head->next;
        head->next = head->next->next->next;
        head->next->next = ptr;
        ptr->next->next = NULL;
    }
    else
    {
        Node *h1,*h2,*np,*n1,*n2;
        h1 = head;
        h2 = head->next->next;
        while(h2 != NULL && h2->next != NULL)
        {
            h1 = h1->next;
            h2 = h2->next->next;
        }       
        if(h2 == NULL)
        {
            h2 = h1->next;
            h1->next = np = NULL;
        }
        else
        {
            h2 = h1->next->next;
            np = h1->next;
            h1->next = NULL;
            np->next = NULL;
        }
        h1 = head;
        h2 = reverse(h2);
        while(h1->next != NULL && h2->next != NULL)
        {   
            n1 = h1->next;
            n2 = h2->next;
            h1->next = h2;
            h2->next = n1;
            h1 = n1;
            h2 = n2;
        }
        h1->next = h2;
        h2->next = np;
    }
}