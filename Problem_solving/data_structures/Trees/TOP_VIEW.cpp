#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        pair<Node*,int>curr;
        map<int,int>m1;
        map<int,bool>m2;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(!m2[curr.second])
            {
                m1[curr.second] = curr.first->data;
                m2[curr.second] = true;
            }
            if(curr.first->left != NULL)
            {
                q.push(make_pair(curr.first->left, curr.second-1));
            }
            if(curr.first->right != NULL)
            {
                q.push(make_pair(curr.first->right,curr.second+1));
            }
        }
        for(auto it = m1.begin();it != m1.end(); it++)
        {
            cout<<it->second<<" ";
        }
        cout<<endl;
    }
};
int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}