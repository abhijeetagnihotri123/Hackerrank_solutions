#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

vector<int> verticalSum(Node *root);
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        vector <int> res = verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}
int left_right_width(Node *root,bool mode)
{
    int width=0;
    if(mode)
    {
        root = root->left;
        while(root != NULL)
        {
            root = root->left;
            width++;
        }
    }
    else
    {
        root = root->right;
        while(root != NULL)
        {
            root = root->right;
            width++;
        }
    }
    return width;
}
void vertical_sum(Node *root,int index,vector<int>&result)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        vertical_sum(root->left,index-1,result);
        result[index] += root->data;
        vertical_sum(root->right,index+1,result);
    }   
}
vector<int> verticalSum(Node *root)
{
    int left_widht = left_right_width(root,true);
    int right_width = left_right_width(root,false);
    int total_elements = left_widht+right_width+1;
    vector<int>result(total_elements,0);
    int index = left_widht;
    vertical_sum(root,index,result);
    return result;
}