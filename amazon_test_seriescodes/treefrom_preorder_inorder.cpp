#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		
		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
int search(int in[],int ele,int FI,int LI)
{
    for(int i=FI;i<=LI;i++)
    {
        if(in[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
Node* buildTreeaux(int in[],int pre[],int start,int end,int n,int &index)
{
    if(start > end)
    {
        return NULL;
    }
    Node *node = new Node(pre[index++]);
    if(start == end)
    {
        return node;
    }
    int ind = search(in,node->data,start,end);
    node->left = buildTreeaux(in,pre,start,ind-1,n,index);
    node->right = buildTreeaux(in,pre,ind+1,end,n,index);
    return node;
}
Node* buildTree(int in[],int pre[], int n)
{   
    int start = 0;
    int end = n-1;
    int index = 0;
    Node *root = buildTreeaux(in,pre,start,end,n,index);
    return root;
}