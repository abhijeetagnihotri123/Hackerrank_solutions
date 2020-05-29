node *Create_new_Node(int);
node* insert(node *,int);
node* LeftRotate(node *);
node* RightRotate(node *);
int height(node*);
int max(int,int);
node *Create_new_Node(int n)
{   
    node *ptr=NULL;
    ptr=new node;
    ptr->val=n;
    ptr->left=ptr->right=NULL;
    ptr->ht=0;
    return ptr;
}
int height(node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {    
        return root->ht;
    }
}
node *RightRotate(node *y)
{
    node *x=y->left;
    node *T2=x->right;
    x->right=y;
    y->left=T2;
    x->ht=max(height(x->left),height(x->right))+1;
    y->ht=max(height(y->left),height(y->right))+1;
    return x;
}
node *LeftRotate(node *x)
{
    node *y=x->right;
    node *T1=y->left;
    y->left=x;
    x->right=T1;
    x->ht=max(height(x->left),height(x->right))+1;
    y->ht=max(height(y->left),height(y->right))+1;
    return y;
}
node* insert(node *root,int val)
{    
    if(root==NULL){
        root=Create_new_Node(val);
        return root;   
    }
    if(root->val < val){
        root->right = insert(root->right, val);
    }
    else if(root->val > val){
        root->left = insert(root->left, val);
    }
    
    root->ht=max(height(root->left),height(root->right))+1;
    
    int bal = height(root->left) - height(root->right);
    
    
    if(bal <= -2 and val > root->right->val){
        root = LeftRotate(root);
    }
    if(bal >= 2 and val < root->left->val){
        root = RightRotate(root);
    }
    if(bal <= -2 and val < root->right->val){
        root->right = RightRotate(root->right);
        root = LeftRotate(root);
    }
    if(bal >= 2 and val > root->left->val){
        root->left = LeftRotate(root->left);
        root = RightRotate(root);
    }
  
    return root;
}
int max(int a,int b)
{
    return a>b?a:b;
}

