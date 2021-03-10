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


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
int minTime(Node* root, int target) ;

void build_graph(map<Node*,Node*>&m,Node *node,Node *parentNode)
{   
    if(node == NULL)
    {
        return ;
    }
    else
    {
        m[node] = parentNode;
        build_graph(m,node->left,node);
        build_graph(m,node->right,node);        
    }
}
Node *findLeafNode(Node *root,int target)
{
    queue<Node*>q;
    q.push(root);
    Node *result = NULL;
    while(!q.empty())
    {
        Node *current = q.front();
        q.pop();
        if(current->data == target && (current->left == NULL && current->right == NULL))
        {
            result = current;
            break;
        }
        if(current->left != NULL)
        {
            q.push(current->left);
        }
        if(current->right != NULL)
        {
            q.push(current->right);
        }
    }
    return result;
}
int minTime(Node *root ,int target)
{   
    if(root == NULL)
    {
        return 0;
    }
    map<Node*,Node*>m;
    build_graph(m,root,NULL);
    Node *lNode = findLeafNode(root,target);
    int level = 0;
    set<Node*>s;
    queue<Node*>q;
    q.push(lNode);
    s.insert(lNode);
    Node *current = NULL;
    Node *parent = NULL; 
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            current = q.front();
            q.pop();
            if(current->left != NULL && s.find(current->left) == s.end())
            {
                q.push(current->left);
                s.insert(current->left);
            }
            if(current->right != NULL && s.find(current->right) == s.end())
            {
                q.push(current->right);
                s.insert(current->right);
            }
            parent = m[current];
            if(parent != NULL && s.find(parent) == s.end())
            {
                q.push(parent);
                s.insert(parent);
            }
        }
        level++;
    }
    return level-1;
}
int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        cout<<minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}