#include <iostream>
using namespace std;

int FindRotationCount(int *,int &);
int main()
{   
    int n;
    cin>>n;
    int *a;
    a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<FindRotationCount(a,n);
    delete(a);
    return 0;
}
int FindRotationCount(int *A,int &n)
{
    int l,r,mid;
    l = 0;
    r = n-1;
    int count = -1;
    while(l<=r)
    {
        if(A[l]<=A[r])
        {
            count = l;
            break;
        }
        else
        {
            mid = (l+r);
            mid = mid>>1;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            if(A[mid] <= A[next] && A[mid] <= A[prev])
            {
                count = mid;
                break;
            }
            else if(A[mid] <= A[r])
            {
                r = mid-1;
            }
            else if(A[mid] >= A[l])
            {
                l = mid+1;
            }
        }
    }
    return count;
}