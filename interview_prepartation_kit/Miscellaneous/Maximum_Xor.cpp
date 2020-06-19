#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    Node *nodes[2];
};
Node *root,*ptr,*newptr;
Node *Create_new_node(void);
void insert(int);
int findMaxXor(int);
int main()
{   
    root = NULL;
    int n,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert(ele);
    }
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<findMaxXor(arr[i])<<endl;
    }
    return 0;
}
void insert(int n)
{   
    Node *current;
    if(root == NULL)
    {
        root = Create_new_node();
        current = root;
        for(int i=31;i>=0;i--)
        {
            int b = (n>>i) & 1;
            if(b == 0)
            {
                if(current->nodes[0]==NULL)
                {
                    current->nodes[0] = Create_new_node();
                }
                current = current->nodes[0];
            }
            else
            {
                if(current->nodes[1]==NULL)
                {
                    current->nodes[1] = Create_new_node();
                }
                current = current->nodes[1];
            }
        }
    }
    else
    {
        current = root;
        for(int i=31;i>=0;i--)
        {
            int b = (n>>i) & 1;
            if(b == 0)
            {
                if(current->nodes[0] == NULL)
                {
                    current->nodes[0] = Create_new_node();
                }
                current = current->nodes[0];
            }
            else
            {
                if(current->nodes[1] == NULL)
                {
                    current->nodes[1] = Create_new_node();
                }
                current = current->nodes[1];
            }
        }
    }
}
Node *Create_new_node(void)
{
    ptr = new Node;
    ptr->nodes[0]=ptr->nodes[1]=NULL;
    return ptr;
}
int findMaxXor(int ele)
{
    Node *current = root;
    int curr_xor=0;
    int value;
    for(int j=31;j>=0;j--)
    {   
        value = ele;
        int b = (value>>j)&1;
        if(b==0)
        {
            if(current->nodes[1] != NULL)
            {
                curr_xor+=(1<<j);
                current = current->nodes[1];
            }
            else if(current->nodes[0] != NULL)
            {   
                current = current->nodes[0];
            }
            else
            {
            }
        }
        else
        {
            if(current->nodes[0] != NULL)
            {   
                current = current->nodes[0];
                curr_xor+=(1<<j);
            }
            else if(current->nodes[1] != NULL)
            {   
                current = current->nodes[1];
            }
            else
            {
            }
        }
    }
    return curr_xor;
}