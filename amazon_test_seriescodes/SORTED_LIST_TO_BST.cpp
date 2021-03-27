#include <bits/stdc++.h>
using namespace std;

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
void InOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        InOrder(root->left);
        InOrder(root->right);
    }
}

Node* sortedArrayToBST(vector<int>&);

int main() {
    int t, n, k;
    cin >> t;
    Node *root = NULL;
    while (t--) {
        cin >> n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {   
            cin>>k;
            v.push_back(k);
        }
        root = sortedArrayToBST(v);
        InOrder(root);
        cout << endl;
    }
    return 0;
}
Node *sortedArrayToBSTaux(vector<int>&a,int l,int r)
{
    if(l>r)
    {
        return nullptr;
    }
    int d = r-l;
    d = d>>1;
    int mid = l+d;
    Node *node = new Node(a[mid]);
    if(l == r)
    {
        return node;
    }
    else
    {
        node->left = sortedArrayToBSTaux(a,l,mid-1);
        node->right = sortedArrayToBSTaux(a,mid+1,r);
        return node;
    }
}
Node *sortedArrayToBST(vector<int>&a)
{
    int n = a.size();
    if(n == 0)
    {
        return NULL;
    }
    else
    {
        return sortedArrayToBSTaux(a,0,n-1);
    }
}