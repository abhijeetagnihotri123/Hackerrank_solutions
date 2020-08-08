#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}
void printPreorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    else
    {
        cout<<n->data<<" ";
        printPreorder(n->left);
        printPreorder(n->right);
    }
}
void printPostorder(Node *n)
{
    if(n==NULL){return;}
    else{printPostorder(n->left);printPostorder(n->right);cout<<n->data<<" ";}
}
Node* insertToAVL( Node* node, int data);

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        
        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
        printPreorder(root);
        cout<<endl;
        printPostorder(root);
        cout<<endl;
    }
    return 0;
}
int max(int &a,int &b)
{
    return a>=b?a:b;
}
int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}
Node *Create_new_node(int data)
{
    Node *newptr = new Node(data);
    return newptr;
}
Node *LeftRotate(Node *x)
{
    Node *y = x->right;
    Node *T1 = y->left;
    y->left = x;
    x->right = T1;
    int h1,h2;
    h1 = height(x->left);
    h2 = height(x->right);
    x->height = max(h1,h2)+1;
    h1 = height(y->left);
    h2 = height(y->right);
    y->height = max(h1,h2)+1;
    return y;
}
Node *RightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    y->left = T2;
    x->right = y;
    int h1,h2;
    h1 = height(x->left);
    h2 = height(x->right);
    x->height = max(h1,h2)+1;
    h1 = height(y->left);
    h2 = height(y->right);
    y->height = max(h1,h2)+1;
    return x;
}
Node *insertToAVL(Node *node, int data)
{
    if(node == NULL)
    {
        node = Create_new_node(data);
        return node;
    }
    if(node->data <= data)
    {
        node->right = insertToAVL(node->right,data);
    }
    else if(node->data > data)
    {
        node->left = insertToAVL(node->left,data);
    }
    int h1 = height(node->left);
    int h2 = height(node->right);
    node->height = max(h1,h2)+1;
    int balance_factor = h1-h2;
    if(balance_factor<=-2 && (node->right->data < data))
    {       
        cout<<"LL"<<endl;
        node = LeftRotate(node);
    }
    if(balance_factor>=2 && (node->left->data > data))
    {   
        cout<<"RR"<<endl;
        node = RightRotate(node);
    }
    if(balance_factor>=2 && (node->left->data < data))
    {
        cout<<"LR"<<endl;
        node->left = LeftRotate(node->left);
        node = RightRotate(node);
    }
    if(balance_factor <=-2 && (node->right->data > data))
    {
        cout<<"RL"<<endl;
        node->right = RightRotate(node->right);
        node = LeftRotate(node);
    }
    return node;
}