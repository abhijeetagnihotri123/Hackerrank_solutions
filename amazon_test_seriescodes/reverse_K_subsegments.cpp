#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        head = reverse(head, k);
        printList(head);
    }
     
    return(0);
}

int length(struct node *head)
{
    int c = 0;
    while(head != NULL)
    {
        head = head->next;
        c++;
    }
    return c;
}
struct node *R(struct node *head)
{
    node *current = NULL;
    node *n = NULL;
    node *prev = NULL;
    current = head;
    while(current != NULL)
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    return prev;
}
struct node *reverse(struct node *head,int k)
{
    int n = length(head);
    if(n == k)
    {
        return R(head);
    }
    else
    {
        int num_segments = n/k+1;
        stack<int>s[num_segments];
        struct node *current = head;
        int i=0;
        while(current != NULL)
        {
            s[i/k].push(current->data);
            i++;
            current = current->next;
        }    
        i=0;
        current = head;
        while(i<num_segments)
        {   
            while(!s[i].empty())
            {
                int data = s[i].top();
                current->data = data;
                s[i].pop();
                current=current->next;
            }
            i++;
        }
        return head;
    }
}