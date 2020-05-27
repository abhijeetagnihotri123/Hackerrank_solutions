/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    Node *find(Node *root,int x)
    {
        Node *current=root;
        while(current)
        {   
             if(x > current->data)
             {  
                if(current->right->data==x)
                {
                    break;
                }
                else
                {
                current=current->right;
                }
             }
            else if(x < current->data)
             {
                if(current->left->data==x)
                {
                    break;
                }
                else
                {
                current=current->left;
                }
            }
        }
        return current;
    }
    Node *lca(Node *root, int v1,int v2) {
        Node *current;
        if(v1==v2)
        {
            current= find(root,v1);
        }
        else if(v1==root->data || v2==root->data)
        {
            return root;
        }
        else
        {   
            int max=v1>v2?v1:v2;
            int min=v1<v2?v1:v2;
            if(max>root->data && min<root->data)
            {
            current = root;
            }
            else if(max < root->data)
            {
                current=lca(root->left,max,min);
            }
            else if(min>root->data)
            {   
                current=lca(root->right,max,min);
            }
        }
        return current;
    }
