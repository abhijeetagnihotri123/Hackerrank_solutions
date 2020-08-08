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
Node* deleteFromAVL(Node *node, int data);
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
        char ch;
        cout<<"Want to delete elements from avl tree press y or Y\n";
        cin>>ch;
        while(ch == 'y' || ch == 'Y')
        {
            cout<<"Enter element to be deleted\n";
            int n;
            cin>>n;
            root = deleteFromAVL(root,n);
            cout<<"The Tree with traversals is as follows\n"<<endl;
            printInorder(root);
            cout<< endl;
            printPreorder(root);
            cout<<endl;
            printPostorder(root);
            cout<<endl;
            cout<<"Want to delete more elements\n";
            cin>>ch;
        }
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
        node = LeftRotate(node);
    }
    if(balance_factor>=2 && (node->left->data > data))
    {   
        node = RightRotate(node);
    }
    if(balance_factor>=2 && (node->left->data < data))
    {
        node->left = LeftRotate(node->left);
        node = RightRotate(node);
    }
    if(balance_factor <=-2 && (node->right->data > data))
    {
        node->right = RightRotate(node->right);
        node = LeftRotate(node);
    }
    return node;
}
Node *findMin(Node *root)
{
    while(root->left !=NULL)
    {
        root = root->left;
    }
    return root;
}
int getBalance(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return (root->left->height-root->right->height);
}
Node *deleteFromAVL(Node *root,int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->data < data)
        {
            root->right = deleteFromAVL(root->right,data);
        }
        else if(root->data > data)
        {
            root->left = deleteFromAVL(root->left,data);
        }
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete(root);
                return NULL;
            }   
            else if(root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete(temp);
                return root;
            }
            else if(root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete(temp);
                return root;
            }
            else
            {
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteFromAVL(root->right,temp->data);
                return root;
            }    
        }
        root->height = 1 + max(height(root->left),height(root->right));
        int b = height(root->left)-height(root->right);
        if(b<-1 && getBalance(root->right)<=0)
        {
            root = LeftRotate(root);
        }
        if(b<-1 && getBalance(root->right)>0)
        {
            root->right = RightRotate(root->right);
            root = LeftRotate(root);
        }
        if(b>1 && getBalance(root->left)>=0)
        {
            root = RightRotate(root);
        }
        if(b>1 && getBalance(root->left)<0)
        {
            root->left = LeftRotate(root->left);
            root = RightRotate(root);
        }
    }
    return root;
}