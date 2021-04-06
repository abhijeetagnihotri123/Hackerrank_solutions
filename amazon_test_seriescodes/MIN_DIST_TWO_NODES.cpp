#include <bits/stdc++.h>

using namespace std;

// Tree Node
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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}
int count(Node* root,int val,int level)
{
if(root==NULL)
return -1;
if(root->data==val)
return level;
int d=count(root->left,val,level+1);
if(d!=-1)
return d;
d=count(root->right,val,level+1);
return d;
}
Node* LCA(Node* root,int a,int b)
{
if(root==NULL)
return NULL;
if(root->data==a||root->data==b)
return root;
Node* n1=LCA( root->left, a, b);
Node* n2=LCA( root->right, a, b);
if(n1!=NULL&&n2!=NULL)
return root;
if(n1!=NULL)
return n1;
if(n2!=NULL)
return n2;
}
int findDist(Node* root, int a, int b)
{
if(root==NULL)
return 0;
Node* node =LCA(root,a,b);
int d1=count(node,a,0);
int d2=count(node,b,0);
return d1+d2;
// Your code here
}