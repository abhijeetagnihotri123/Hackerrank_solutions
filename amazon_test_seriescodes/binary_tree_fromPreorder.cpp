#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
Node *constructTreeUtil(int pre[],char preLN[],int &index,int n)
{   
    int i = index;
    if(i==n)
    {
        return NULL;
    }
    Node *temp = new Node(pre[i]);
    index++;
    if(preLN[i] == 'N')
    {
        temp->left = constructTreeUtil(pre,preLN,index,n);
        temp->right = constructTreeUtil(pre,preLN,index,n);
    }
    return temp;
}
Node *constructTree(int n,int pre[],char preLN[])
{
    int index = 0;
    return constructTreeUtil(pre,preLN,index,n);
}