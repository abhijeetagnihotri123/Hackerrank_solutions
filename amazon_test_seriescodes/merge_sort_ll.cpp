#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node *mergeSort(Node *);

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void merge(int *A,int l,int m,int r)
{
    int *B,*C;
    int n1=m-l+1;
    int n2=r-m;
    B=new int[n1];
    C=new int[n2];
    int i=0;
    int j=0;
    int k=l;
    for(i=0;i<n1;i++)
    {
        B[i]=A[l+i];
    }
    for(i=0;i<n2;i++)
    {
        C[i]=A[m+i+1];
    }
    i=0;
    j=0;
    while(i<n1 && j<n2)
    {
        if(B[i]<=C[j])
        {
            A[k]=B[i];
            i++;
        }
        else
        {
            A[k]=C[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=C[j];
        j++;
        k++;
    }
}

void mergesort(int *A,int l,int r)
{
    if(l<r)
    {
        int m = (l+r);
        m = (m>>1);
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,m,r);
    }
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}

void length(Node *h,int &c)
{
    c = 0;
    while(h != NULL)
    {
        c++;
        h = h->next;
    }
}

void copyback(int *A,Node *h)
{
    int i = 0;
    while(h != NULL)
    {
        h->data = A[i++];
        h = h->next;
    }
    delete(A);
}
Node* mergeSort(Node* head) {
    int n;
    int *A;
    length(head,n);
    A = new int[n];
    Node *h = head;
    int i=0;
    while(h != NULL)
    {
        A[i] = h->data;
        h = h->next;
        i++;
    }
    mergesort(A,0,n-1);
    h = head;
    i = 0;
    while(h != NULL)
    {
        h->data = A[i];
        i++;
        h = h->next;
    }
    return head;
}

