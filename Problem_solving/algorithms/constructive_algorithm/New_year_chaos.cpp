#include <bits/stdc++.h>
using namespace std;
void merge(int*,int,int,int,int&);
void mergesort(int *,int,int,int&);
int main()
{   
    
    int T;
    cin>>T;
    while(T--)
    {
        int *A;
        int n;
        cin>>n;
        int f=0;
        A=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]-(i+1)>2)
            {
                f=1;
            }
        }
        if(f==1)
        {
            cout<<"Too chaotic";
        }
        else
        {
            int count=0;
            mergesort(A,0,n-1,count);
            cout<<count;
        }
        delete(A);
        cout<<endl;
    }
    return 0;
}
void mergesort(int *A,int l,int r,int &c)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(A,l,m,c);
        mergesort(A,m+1,r,c);
        merge(A,l,m,r,c);
    }
}
void merge(int *A,int l,int m,int r,int &c)
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
            c+=(n1-i);
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
