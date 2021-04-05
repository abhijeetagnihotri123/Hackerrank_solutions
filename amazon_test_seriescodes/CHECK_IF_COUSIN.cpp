#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
void preorder(Node *root,Node *parent,map<Node*,Node*>&m,Node **p,Node **q,int &x,int &y)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        if(root->data == x)
        {
            *p = root;
        }
        if(root->data == y)
        {
            *q = root;
        }
        m[root] = parent;
        preorder(root->left,root,m,p,q,x,y);
        preorder(root->right,root,m,p,q,x,y);
    }
}
bool isCousins(Node *root,int x,int y)
{
    Node *p = NULL;
    Node *q = NULL;
    map<Node*,Node*>m;
    preorder(root,NULL,m,&p,&q,x,y);
    bool result;
    if(m[p] == m[q])
    {
        result = false;
    }
    else
    {
        Node *current1 = p;
        Node *current2 = q;
        while(current1 != NULL && current2 != NULL)
        {
            if(current1 == current2)
            {
                result = true;
            }
            current1 = m[current1];
            current2 = m[current2];
        }
    }
    return result;
}