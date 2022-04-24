#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    struct box
    {
        int l,w,h;
    };
    static bool compare(box a,box b)
    {
        return a.w*a.l < b.w*b.l;
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
        int len = 3*n;
        box arr[len];
        int index = 0;
        for(int i=0;i<n;i++)
        {
            arr[index].h = height[i];
            arr[index].w = max(width[i],length[i]);
            arr[index++].l = min(width[i],length[i]);

            arr[index].h = width[i];
            arr[index].w = max(length[i],height[i]);
            arr[index++].l = min(length[i],height[i]);

            arr[index].h = length[i];
            arr[index].w = max(width[i],height[i]);
            arr[index++].l = min(width[i],height[i]);
        }
        sort(arr,arr+len,compare);
        int max_length = INT_MIN;
        int lis[len];
        for(int i=0;i<len;i++)
        {
            lis[i] = arr[i].h;
        }
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j].l < arr[i].l && arr[j].w < arr[i].w && lis[i] < lis[j]+arr[i].h)
                {
                    lis[i] = lis[j]+arr[i].h;
                }
            }
        }
        for(int i=0;i<len;i++)
        {
            if(max_length < lis[i])
            {
                max_length = lis[i];
            }
        }
        return max_length;
    }
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
