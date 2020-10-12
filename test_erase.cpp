#include <bits/stdc++.h>
using namespace std;
int main()
{	
	vector<int>v(7);
	for(int i=0;i<7;i++)
	{
		cin>>v[i];
	}
	v.erase(v.begin()+3);
	for(int x : v)
	{
		printf("%d ",x);
	}
	return 0;
}
