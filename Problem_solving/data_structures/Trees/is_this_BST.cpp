/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root) {
		return BST(root,INT8_MIN,__INT_MAX__);
	}
    bool BST(Node *root,int minvalue,int maxvalue)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->data > minvalue && root->data < maxvalue && BST(root->left,minvalue,root->data)&&BST(root->right,root->data,maxvalue))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
