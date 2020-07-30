#include <iostream>
using namespace std;
double max(double a,double b)
{
    return (a>=b?a:b);
}
double min(double a,double b)
{
    return (a<=b?a:b);
}
void swap(int &a,int &b)
{
    int t = a ^ b;
    a = t ^ a;
    b = t ^ b;
}
double MedianOfTwoSorted(int *a,int *b,int n,int m)
{
    if(n>=m)
    {
        return MedianOfTwoSorted(b,a,m,n);
    }
    int x,y;
        x = n;
        y = m;
        int low = 0;
        int high = x;
        double median;
        while(low <= high)
        {
            int PX = (low+high)/2;
            int PY = (x + y + 1)/2-PX;
            int MLX = (PX == 0)?-2147483648:a[PX-1];
            int MIRX = (PX == x)?2147483647:a[PX];

            int MLY = (PY == 0)?-2147483648:b[PY-1];
            int MIRY = (PY == y)?2147483647:b[PY];
            if(MLX <= MIRY && MLY <= MIRX)
            {    
                if((x+y)%2==0)
                {
                    median = (double)(max(MLX,MLY)+min(MIRX,MIRY))/2;
                    break;
                }
                else
                {
                    median = (double)(max(MLX,MLY));
                    break;
                }
            }
            else if(MLX > MIRY)
            {
                high = PX-1;
            }
            else
            {
                low = PX + 1;
            }
        }
    return median;
}
int main()
{   
    int *a,*b;
    int n,m;
    cin>>n>>m;
    a = new int[n];
    b = new int[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    cout<<MedianOfTwoSorted(a,b,n,m);
    delete(b);
    delete(a);
    return 0;
}