#include <bits/stdc++.h>
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
 
 Node *zigZag(Node* head);


int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		Node *ans = zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}
Node *zigZag(Node* head)
{
    bool flag = true;
    Node* current = head;
    while (current->next != NULL) {
        if (flag)
        {
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else 
        {
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }
        current = current->next;
        flag = !flag; 
    }
    return head;
}