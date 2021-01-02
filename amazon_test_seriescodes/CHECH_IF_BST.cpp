
bool isBSTUtil(struct Node* node,int min,int max)
{
    if(node == NULL)
    {
        return true;
    }
    else if(node->data > max || node->data < min)
    {
        return false;
    }
    else
    {
        bool b1 = isBSTUtil(node->left,min,node->data-1);
        bool b2 = isBSTUtil(node->right,node->data+1,max);
        return b1 && b2;
    }
}
bool isBST(Node* root) {
    int Max = INT_MAX;
    int Min = INT_MIN;
    return ISBSTUtil(root,Min,Max);
}
