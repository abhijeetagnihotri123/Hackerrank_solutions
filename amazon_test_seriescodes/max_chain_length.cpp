#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}
bool compare(val v1,val v2)
{
    return v1.second < v2.second;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,compare);
    int i,j;
    vector<int>LIS(n,1);
    int max_len = 1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(p[j].second < p[i].first && LIS[i] < LIS[j]+1)
            {
                LIS[i] = LIS[j]+1;
                if(max_len < LIS[i])
                {
                    max_len = LIS[i];
                }
            }
        }
    }
    return max_len;
}