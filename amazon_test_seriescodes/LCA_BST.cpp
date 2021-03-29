#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
void preorder(Node*,Node*,map<Node*,Node*>&);
Node* lowestCommonAncestor(Node*,Node*,Node*);
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
Node *Find(Node *root,int data)
{
    while(root != NULL)
    {
        if(root->data == data)
        {
            return root;
        }
        else if(root->data > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
int main()
{   
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        int p,q;
        cin>>p>>q;
        Node *P = Find(root,p);
        Node *Q = Find(root,q);
        Node *result = lowestCommonAncestor(root,P,Q);
        cout << result->data<<endl;
   }
   return 0;
} 
void preorder(Node *root,Node *parent,map<Node*,Node*>&m)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        m[root] = parent;
        preorder(root->left,root,m);
        preorder(root->right,root,m);
    }
}
void length(Node *n1,Node *n2,int &l1,int &l2,map<Node*,Node*>&m)
{
    l1 = l2 = 0;
    Node *current = n1;
    while(current != NULL)
    {
        l1++;
        current = m[current];
    }
    current = n2;
    while(current != NULL)
    {
        l2++;
        current = m[current];
    }
}
Node* lowestCommonAncestor(Node* root,Node* p,Node* q)
{
    map<Node*,Node*>m;
    Node *result = NULL;
    preorder(root,NULL,m);
    int l1,l2;
    length(p,q,l1,l2,m);
    int d = (l1>=l2)?(l1-l2):(l2-l1);
    if(l1 >= l2)
    {
        while(d--)
        {
            p = m[p];
        }
    }
    else
    {
        while(d--)
        {
            q = m[q];
        }
    }
    while(p != NULL && q != NULL)
    {
        if(p == q)
        {
            result = p;
            break;
        }
        p = m[p];
        q = m[q];
    }
    return result;
}