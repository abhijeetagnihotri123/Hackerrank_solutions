#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
void levelOrder(struct Node* node);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


void leftViewUtil(Node *root,int c,map<int,bool>&m)
{
    if(root == NULL)
    {
        return ;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        if(!m[c])
        {
            cout<<root->data<<" ";
            m[c]=true;
        }
    }
    else if(root->left != NULL && root->right == NULL)
    {
        if(!m[c])
        {
            cout<<root->data<<" ";
            m[c]=true;
        }
        leftViewUtil(root->left,c+1,m);
    }
    else if(root->right != NULL && root->left == NULL)
    {
        if(!m[c])
        {
            cout<<root->data<<" ";
            m[c]=true;
        }
        leftViewUtil(root->right,c+1,m);
    }
    else
    {
        if(!m[c])
        {
            cout<<root->data<<" ";
            m[c]=true;
        }
        leftViewUtil(root->left,c+1,m);
        leftViewUtil(root->right,c+1,m);
    }
}
void leftView(Node *root)
{   
    int c=0;
    map<int,bool>m;
   leftViewUtil(root,c,m);
}