#include <iostream>
using namespace std;
int kandane_algo(int [],int &);
int main()
{   
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(int);
    cout<<kandane_algo(a,n);
    return 0;
}
int kandane_algo(int a[],int &n)
{
    int MAX_SO_FAR = -2147483648;
    int MAX_ENDING_HERE = 0;
    for(int i=0;i<n;i++)
    {
        MAX_ENDING_HERE += a[i];
        if(MAX_ENDING_HERE > MAX_SO_FAR)
        {
            MAX_SO_FAR = MAX_ENDING_HERE;
        }
        if(MAX_ENDING_HERE < 0)
        {
            MAX_ENDING_HERE = 0;
        }
    }
    return MAX_SO_FAR;
}