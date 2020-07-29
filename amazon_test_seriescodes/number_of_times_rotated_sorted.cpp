#include <iostream>
using namespace std;

int main()
{   
    int n,*a;
    cout<<"Enter size"<<endl;
    cin>>n;
    a = new int[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l,h,mid;
    l = 0;
    h = n-1;
    int pivot_index,prev,next;
    while(l<=h)
    {
        mid = (l+h);
        mid = (mid>>1);
        prev = (mid+n-1)%n;
        next = (mid+1)%n;
        if(a[l] <= a[h])
        {
            pivot_index = l;
            break;
        }
        else if(a[mid] <= a[prev] && a[mid] <= a[next])
        {
            pivot_index = mid;
            break;
        }
        else if(a[mid] <= a[h])
        {
            h = mid-1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout<<pivot_index;
    delete(a);
    return 0;
}