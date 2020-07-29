// array is sorted in circular fashion

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>&arr,int l,int h,int key)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[l] <= arr[mid]) {
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        return search(arr, mid + 1, h, key);
    }
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);
    return search(arr, l, mid - 1, key);
}
int main()
{   
    int *a,n,key;
    cout<<"Enter size\n";
    cin>>n;
    a = new int[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>key;
    // now follows 3 cases
    int low,high,mid;
    low = 0;
    high = n-1;
    int index = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        //mid = (mid>>1);
        if(a[mid] == key)
        {
            index = mid;
            break;
        }
        else if(a[mid] <= a[high])
        {
            if(key >= a[mid] && key < a[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        else if(a[mid] >= a[low])
        {
            if(key >= a[low] && key <= a[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    cout<<index<<endl;
    delete(a);
    return 0;
}