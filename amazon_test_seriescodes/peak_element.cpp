#include <iostream>

using namespace std;

int max(int &a,int &b)
{
    return a>=b?a:b;
}
int peakElement(int a[],int n)
{
    if(n==0)
    {
        return -1;
    }
    else if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return a[0]>=a[1]?0:1;
    }
    else if(n==3)
    {
        int i1 = a[0]>=a[1]?0:1;
        int i2 = a[1]>=a[2]?1:2;
        return a[i1]>=a[i2]?i1:i2;
    }
    else
    {
        int l,r,mid;
        l = 0;
        r = n-1;
        int index = -1;
        while(l<=r)
        {
            mid = (l+r);
            mid = (mid>>1);
            if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
            {
                index = mid;
                break;
            }
            else if(a[mid-1] > a[mid])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return index;   
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}