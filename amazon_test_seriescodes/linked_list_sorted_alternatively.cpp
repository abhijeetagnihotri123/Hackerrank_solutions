#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}
void sort(Node **head)
{
    Node *current1 = *head;
    Node *current2 = current1->next;
    vector<int>a1,a2;
    while(current1 != NULL)
    {   
        a1.push_back(current1->data);
        if(current1->next == NULL)
        {
            break;
        }
        current1 = current1->next->next;
    }
    while(current2 != NULL)
    {   
        a2.push_back(current2->data);
        if(current2->next == NULL)
        {
            break;
        }
        current2 = current2->next->next;
    }
    reverse(a2.begin(),a2.end());
    current1 = *head;
    vector<int>a3;
    int i,j,n,m;
    n = a1.size();
    m = a2.size();
    i=j=0;
    while(i<n && j<m)
    {
        if(a1[i] <= a2[j])
        {
            a3.push_back(a1[i]);
            i++;
        }
        if(a2[j] <= a1[i])
        {
            a3.push_back(a2[j]);
            j++;
        }
    }
    while(i<n)
    {
        a3.push_back(a1[i]);
        i++;
    }
    while(j<m)
    {
        a3.push_back(a2[j]);
        j++;
    }
    current1 = *head;
    for(i=0;i<a3.size();i++)
    {
        current1->data = a3[i];
        current1 = current1->next;
    }
}