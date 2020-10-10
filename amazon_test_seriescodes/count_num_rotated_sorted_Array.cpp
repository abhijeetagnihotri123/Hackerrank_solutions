#include<bits/stdc++.h>
using namespace std; 


int NumberOfRotations(int a[], int n);

// Driver code to test above functions
int main()
{

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];


        cout << NumberOfRotations(a, n) << "\n";
    }


    return 0; 
}
int NumberOfRotations(int a[],int n)
{
    int low = 0;
    int mid,next,prev;
    int high = n-1;
    int index = -1;
    while(low <= high)
    {
        if(a[low] <= a[high])
        {
            index = low;
            break;
        }
        mid = (low+high)/2;
        next = (mid + 1)%n;
        prev = (mid-1+n)%n;
        if(a[mid] <= a[next] && a[mid] <= a[prev])
        {
            index = mid;
            break;
        }
        else if(a[mid]<=a[high])
        {
            high = mid-1;
        }
        else if(a[mid] >= a[low])
        {
            low = mid+1;
        }
    }
    return index;
}