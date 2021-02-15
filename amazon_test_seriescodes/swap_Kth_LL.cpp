#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
Node *swapkthnode(Node* head, int num, int k)
{
	if(head == NULL || head->next == NULL || k > num || ((k<<1) == (num+1)))
	{
		return head;
	}
	else if(num == 2)
	{
		Node *current = head;
		Node *tmp = head->next;
		tmp->next = current;
		current->next = NULL;
		return tmp;
	}
	else if(k == 1 || k == num)
	{
		Node *current = head->next;
		Node *tmp = head;
		Node *newHead;
		while(current->next->next != NULL)
		{
			current = current->next;
		}
		newHead = current->next;
		newHead->next = tmp->next;
		current->next = tmp;
		tmp->next = NULL;
		return newHead;
	}
	else
	{
		int k1 = num-k+1;
		Node *s1,*s2;
		s1 = s2 = head;
		while(k>2 && k1 > 2)
		{	
			s1 = s1->next;
			s2 = s2->next;
			k--;
			k1--;
		}
		while(k>2)
		{
			s1 = s1->next;
			k--;
		}
		while(k1 > 2)
		{
			s2 = s2->next;
			k1--;
		}
		if(s1->next == s2)
		{	
			Node *n = s2->next;
			s1->next->next = s2->next->next;
			n->next = s1->next;
			s1->next = n;
		}
		else if(s2->next == s1)
		{
			Node *n = s1->next;
			s2->next->next = s1->next->next;
			n->next = s2->next;
			s2->next = n;
		}
		else
		{
			Node *n1,*n2,*n11,*n22;
			n1 = s1->next->next;
			n11 = s1->next;
			n2 = s2->next->next;
			n22 = s2->next;
			s1->next = n22;
			n11->next = n2;
			s2->next = n11;
			n22->next = n1;
		}
		return head;
	}
}