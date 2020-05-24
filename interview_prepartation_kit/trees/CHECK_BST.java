/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node class is defined as follows:
    class Node {
        int data;
        Node left;
        Node right;
     }
*/
boolean checkBST(Node root) {
    return BST(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
}
boolean BST(Node root,int min,int max)
{
    if(root==null)
    {
        return true;
    }
    if(root.data > min && root.data < max && BST(root.left,min,root.data) && BST(root.right,root.data,max))
    {
        return true;
    }
    else
    {
        return false;
    }
}