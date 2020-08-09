#include<bits/stdc++.h>
using namespace std;

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
class solver
{
private:

public:

    void build_graph(map<Node*,Node*>&m,Node *node,Node *parentNode)
    {
        if(node == NULL)
        {
            return;
        }
        else
        {
            m[node] = parentNode;
            build_graph(m,node->left,node);
            build_graph(m,node->right,node);   
        }
    }
    Node *findTargetNode(Node *root,int target)
    {
        queue<Node*>q;
        q.push(root);
        Node *result = NULL;
        while(!q.empty())
        {
            Node *current = q.front();
            if(current->data == target)
            {
                result =  current;
                break;
            }
            q.pop();
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
    vector<int>copyQ(queue<Node*>&q)
    {
        vector<int>v;
        while(!q.empty())
        {   
            Node *current = q.front();
            v.push_back(current->data);
            q.pop();
        }
        return v;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        map<Node*,Node*>m;
        build_graph(m,root,NULL);
        Node *tNode = findTargetNode(root,target);
        // got the target node now first traverse downwards
        set<Node*>s;
        bool flag = false;
        queue<Node*>q;
        q.push(tNode);
        s.insert(tNode);
        map<Node*,bool>visited;
        Node *current = NULL;
        int level = 0;
        vector<int>v;
        while(!q.empty())
        {
            if(level == k)
            {
                v = copyQ(q);
            }
            int n = q.size();
            while (n--)
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
                Node *parent = m[current];
                if(parent != NULL && s.find(parent) == s.end())
                {
                    q.push(parent);
                    s.insert(parent);
                }
            }
            level++;
        }
        return v;
    }
};
int main()
{
    int t;
    cin>>t;
    getchar();
    
    solver x = solver();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}