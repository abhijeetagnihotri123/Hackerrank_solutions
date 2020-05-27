#include <iostream>
#include <cstddef>
	
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
  
    void preOrder(Node *root) {

          if( root == NULL )
              return;

          std::cout << root->data << " ";

          preOrder(root->left);
          preOrder(root->right);
      }

/* you only have to complete the function given below.  
Node is defined as  

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
/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value)
{
   node * r = root;
   node *rs = NULL; 
   node *ls = NULL;
   
   if(root == NULL){
       root = new node;
       root->data = value;
       root->left = root->right = NULL;
   }
   
   while(r != NULL){
       if(value < r->data){
           if(r->left == NULL) ls = r;
           r = r->left;
       } else if(value > r->data) {
           if(r->right == NULL) rs = r;
           r = r->right;
       }
   }
   
   r = new node;
   r->data = value;
   r->left = r->right = NULL;
   if(ls != NULL) ls->left = r;
   if(rs != NULL) rs->right = r;
   
   return root;
}

}; //End of Solution

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
	myTree.preOrder(root);
    return 0;
}
