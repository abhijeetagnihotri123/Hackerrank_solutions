#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    pair<int,int> diameter_util(Node *root)
    {
        if(root == NULL)
        {
            return make_pair(0,0);
        }
        else
        {
            pair<int,int> l = diameter_util(root->left);
            pair<int,int> r = diameter_util(root->right);
            int IP = max(l.second,r.second);
            if(l.first+r.first+1>IP)
            {
                IP = l.first+r.first+1;
            }
            return make_pair(max(l.first,r.first)+1,IP);
        }
    }
    int diameter(Node* root)
    {   
        int result;
        if(root == NULL)
        {
            result = 0;
        }
        else
        {
            pair<int,int>r = diameter_util(root);
            result = max(r.first,r.second);
        }
        return result;
    }

};
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}