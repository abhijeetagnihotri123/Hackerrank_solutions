#include <iostream>
using namespace std;
void quicksort(int *,int,int);
int partition(int*,int,int);
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
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete(a);
    return 0;
}
int partition(int *a,int l,int r)
{
    int pivot = a[r];
    int PI = l;
    for(int i=l;i<r;i++)
    {
        if(a[i]<=pivot)
        {
            int t = a[i] ^ a[PI];
            a[i] = t ^ a[i];
            a[PI] = t ^ a[PI];
            PI++;
        }
    }
    int t = a[r] ^ a[PI];
    a[r] = t ^ a[r];
    a[PI] = t ^ a[PI];
    return PI;
}
void quicksort(int *a,int l,int r)
{
    if(l<r)
    {
        int p = partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}