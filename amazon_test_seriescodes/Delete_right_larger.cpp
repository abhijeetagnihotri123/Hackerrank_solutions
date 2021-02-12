#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node *compute(Node *head);

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}
Node *reverse(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *n;
    while(current != NULL)
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    return prev;
}
Node *compute(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    else if(head->next->next == NULL)
    {
        return (head->data<=head->next->data)?head->next:head;
    }
    else
    {
        head = reverse(head);
        Node *start = head;
        while(start->next != NULL)
        {
            if(start->next->data < start->data)
            {
                Node *temp = start->next;
                start->next = temp->next;
                delete(temp);
            }
            else
            {
                start = start->next;
            }
        }
        return reverse(head);
    }
}