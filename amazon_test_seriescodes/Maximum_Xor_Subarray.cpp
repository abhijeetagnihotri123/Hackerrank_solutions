#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:

    struct Node
    {
        Node *nodes[2];
    };
    Node *root,*ptr;

    Node *getNode()
    {
        ptr = new Node;
        if(ptr != NULL)
        {
            ptr->nodes[0] = ptr->nodes[1] = NULL;
        }
        return ptr;
    }

    void insert(Node *root,int n)
    {
        for(int i=31;i>=0;i--)
        {
            int b = (n>>i) & 1;
            if(root->nodes[b] == NULL)
            {
                root->nodes[b] = getNode();
            }
            root = root->nodes[b];
        }
    }

    int get_max_xor(Node *root,int x)
    {
        int curr_xor=0;
        for(int j=31;j>=0;j--)
        {   
            int b = (x>>j)&1;
            if(root->nodes[1^b] != NULL)
            {
                curr_xor += (1<<j);
                root = root->nodes[1^b];
            }
            else if(root->nodes[b] != NULL)
            {
                root = root->nodes[b];
            }
            else
            {

            }
        }
        return curr_xor;
    }

    int maxSubarrayXOR(int N, int arr[])
    {       
        root = getNode();
        insert(root,0);
        insert(root,arr[0]);
        for(int i = 1 ; i < N ; i++)
        {
            arr[i] = arr[i] ^ arr[i-1];
            insert(root,arr[i]);
        }
        int max_xor_value = INT_MIN;
        for(int i = 0 ; i < N ; i++)
        {
            int xor_value = get_max_xor(root,arr[i]);
            max_xor_value = max(max_xor_value,xor_value);
        }
        return max_xor_value;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 