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

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}
vector<int> zigZagTraversal(Node *root)
{
    if(root == NULL)
    {
        vector<int>a;
        return a;
    }
    int level = 0;
    deque<Node*>q;
    vector<int>v;
    q.push_back(root);
    //v.push_back(root);
    Node *current = NULL;
    v.push_back(root->data);
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            if(level%2==1)
            {
                current = q.front();
                q.pop_front();
                if(current->left != NULL)
                {   
                    v.push_back(current->left->data);
                    q.push_back(current->left);
                }
                if(current->right != NULL)
                {   
                    v.push_back(current->right->data);
                    q.push_back(current->right);
                    //v.push_back(current->right);
                }
            }
            else
            {
                current = q.back();
                q.pop_back();
                if(current->right != NULL)
                {   
                    v.push_back(current->right->data);
                    q.push_front(current->right);
                    //v.push_back(current->right);
                }
                if(current->left != NULL)
                {   
                    v.push_back(current->left->data);
                    q.push_front(current->left);
                    //v.push_back(current->left);
                }
            }    
        }
        level++;
    }
    return v;
}