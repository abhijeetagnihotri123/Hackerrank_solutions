#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
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


class Solution{ 
public:

    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *n = NULL;
        while(head != NULL)
        {
            n = head->next;
            head->next = prev;
            prev = head;
            head = n;
        }   
        return prev;
    }

    void advance_pointers(Node **Fast,Node **Slow)
    {   
        Node *fast = *Fast;
        Node *slow = *Slow;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        *Fast = fast;
        *Slow = slow;
    }

    void segregate_Lists(Node **Fast,Node **Slow,Node **next_pointer)
    {
        Node *fast = *Fast;
        Node *slow = *Slow;
        Node *np = *next_pointer;
        if(fast == NULL)
        {
            fast = slow->next;
            slow->next = NULL;
        }
        else
        {
            np = slow->next;
            fast = np->next;
            np->next = NULL;
            slow->next = NULL;
        }
        *Fast = fast;
        *Slow = slow;
        *next_pointer = np;
    }

    void advance_adjust_pointers(Node **head,Node **fast,Node *np)
    {
        Node *n1 = NULL;
        Node *n2 = NULL;
        Node *h1 = *head;
        Node *h2 = reverse(*fast);
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
    
    void reorderListUtil(Node* head)
    {
        Node *slow = head;
        Node *fast = head->next->next;
        Node *np = NULL;
        advance_pointers(&fast,&slow);
        segregate_Lists(&fast,&slow,&np);
        advance_adjust_pointers(&head,&fast,np);
    }
    
    void reorderList(Node* head) 
    {
        if(head->next != NULL && head->next->next != NULL)
        {
            reorderListUtil(head);
        }
    }
};



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
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
