#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
int search(int in[],int ele,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
Node *buildTreeaux(int in[],int post[],int start,int end,int n,int &index)
{
    if(start > end)
    {
        return NULL;
    }
    Node *tnode = new Node(post[index--]);
    if(start == end)
    {
        return tnode;
    }
    int ind = search(in,tnode->data,start,end);
    tnode->right = buildTreeaux(in,post,ind+1,end,n,index);
    tnode->left = buildTreeaux(in,post,start,ind-1,n,index);
    return tnode;
}
Node *buildTree(int in[],int post[],int n)
{   
    int index = n-1;
    Node *root = buildTreeaux(in,post,0,n-1,n,index);
    return root;
}