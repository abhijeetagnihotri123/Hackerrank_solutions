#include <bits/stdc++.h>
using namespace std;
void merge(int*,int,int,int);
void mergesort(int *,int,int);
int main()
{   
        int *A;
        int n;
        cin>>n;
        A=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
            int count=0;
            mergesort(A,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        delete(A);
    return 0;
}
void mergesort(int *A,int l,int r)
{
    if(l<r)
    {
        int m = (l+r);
        m = (m>>1);
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,m,r);
    }
}
void merge(int *A,int l,int m,int r)
{
    int *B,*C;
    int n1=m-l+1;
    int n2=r-m;
    B=new int[n1];
    C=new int[n2];
    int i=0;
    int j=0;
    int k=l;
    for(i=0;i<n1;i++)
    {
        B[i]=A[l+i];
    }
    for(i=0;i<n2;i++)
    {
        C[i]=A[m+i+1];
    }
    i=0;
    j=0;
    while(i<n1 && j<n2)
    {
        if(B[i]<=C[j])
        {
            A[k]=B[i];
            i++;
        }
        else
        {
            A[k]=C[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=C[j];
        j++;
        k++;
    }
}