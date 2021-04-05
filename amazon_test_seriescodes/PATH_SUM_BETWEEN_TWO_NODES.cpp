#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution
{
    public:
    void build_graph(Node *root,Node *parent,map<Node*,Node*>&m)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            m[root] = parent;
            build_graph(root->left,root,m);
            build_graph(root->right,root,m);
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
    void levelOrderTraversal(Node *root,Node **p,Node **q,int n1,int n2)
    {
        queue<Node*>Q;
        Node *current = NULL;
        Node *t1 = NULL;
        Node *t2 = NULL; 
        Q.push(root);
        while(!Q.empty())
        {
            current = Q.front();
            Q.pop();
            if(current->data == n1)
            {
                t1 = current;
            }
            if(current->data == n2)
            {
                t2 = current;
            }
            if(current->left != NULL)
            {
                Q.push(current->left);
            }
            if(current->right != NULL)
            {
                Q.push(current->right);
            }
        }
        *p = t1;
        *q = t2;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {   
        Node *p = NULL;
        Node *q = NULL;
        Node *result = NULL;
        levelOrderTraversal(root,&p,&q,n1,n2);
        if(p != NULL && q != NULL)
        {
            map<Node*,Node*>m;
            build_graph(root,NULL,m);
            int l1,l2;
            length(p,q,l1,l2,m);
            int d = (l1>=l2)?(l1-l2):(l2-l1);
            int sum = 0;
            if(l1 >= l2)
            {
                while(d--)
                {   
                    sum += p->data;
                    p = m[p];
                }
            }
            else
            {
                while(d--)
                {   
                    sum += q->data;
                    q = m[q];
                }
            }
            while(p != NULL && q != NULL)
            {
                if(p == q)
                {
                    result = p;
                    sum += result->data;
                    break;
                }
                sum += p->data+q->data;
                p = m[p];
                q = m[q];
            }
            cout<<sum<<endl;
        }
        return result;
    }
};
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}