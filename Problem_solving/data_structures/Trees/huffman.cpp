

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s) {
    node *temp=root;
    int n=s.length();
    string str="";
    for(int i=0;i<n;i++)
    {
        temp=s[i]=='1'?temp->right:temp->left;
        if(temp->left==NULL && temp->right==NULL)
        {
            str+=temp->data;
            temp=root;
        }
    }
    std::cout<<str<<endl;
}


