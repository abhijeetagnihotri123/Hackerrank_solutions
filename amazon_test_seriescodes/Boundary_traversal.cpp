#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

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
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
void left(Node *root,vector<int>&result)
{   
    if(root->left == NULL)
    {
        if(root->right == NULL)
        {
            return;
        }
        else
        {
            root = root->right;
        }
    }
    else
    {
        root = root->left;
    }
    while(root->left != NULL || root->right != NULL)
    {   
        result.push_back(root->data);
        if(root->left == NULL)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}
void leaf(Node *root,vector<int>&result)
{
    if(root == NULL)
    {
        return;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        result.push_back(root->data);
    }
    else
    {
        leaf(root->left,result);
        leaf(root->right,result);
    }
}
void right(Node *root,vector<int>&result)
{
    vector<int>a;
    if(root->right == NULL)
    {
        if(root->left == NULL)
        {
            return ;
        }
        else
        {
            root = root->left;
        }
    }
    else
    {
        root = root->right;
    }
    while(root->left != NULL || root->right != NULL)
    {
        a.push_back(root->data);
        if(root->right == NULL)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if(a.size()>0)
    {
        for(int i=a.size()-1;i>=0;i--)
        {
            result.push_back(a[i]);
        }
    }
}
vector<int> printBoundary(Node *root)
{   
    vector<int>result;
    result.push_back(root->data);
    left(root,result);
    leaf(root,result);
    right(root,result);
    return result;
}