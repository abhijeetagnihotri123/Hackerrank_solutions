#include <bits/stdc++.h>
using namespace std;
int main () {
        int n;
        cin>>n;
        vector<int>sticks(n);
        for(int i=0;i<n;i++)
        {
            cin>>sticks[i];
        }
        if(n==1 || n==2)
        {
            vector<int>arr(1);
            arr[0]=-1;
            for(int i=0;i<arr.size();i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else if(n==3)
        {
            sort(sticks.begin(),sticks.end());
            if(sticks[2] < (sticks[1]+sticks[0]))
            {
                vector<int>arr(3);
                arr[0]=sticks[0];
                arr[1]=sticks[1];
                arr[2]=sticks[2];
                for(int i=0;i<arr.size();i++)
                 {
                cout<<arr[i]<<" ";
                 }
            }
            else if(sticks[0]==sticks[1] && sticks[1]==sticks[2] && sticks[2]==sticks[0])
            {
                vector<int>arr(3);
                arr[0]=sticks[0];
                arr[1]=sticks[1];
                arr[2]=sticks[2];
                for(int i=0;i<arr.size();i++)
                {
                    cout<<arr[i]<<" ";
                }
            }
            else 
            {
                vector<int>arr(1);
                arr[0]=-1;
                for(int i=0;i<arr.size();i++)
                {
                    cout<<arr[i]<<" ";
                }
            }
        }
        else
        {   int i;
            int f=0;
            sort(sticks.begin(),sticks.end());
            for(i=n-1;i>=2;i--)
            {
                if(sticks[i] < (sticks[i-1]+sticks[i-2]))
            {
                vector<int>arr(3);
                arr[0]=sticks[i-2];
                arr[1]=sticks[i-1];
                arr[2]=sticks[i];
                f=1;
                    for(int i=0;i<arr.size();i++)
            {
                cout<<arr[i]<<" ";
            }
                break;
            }
            else if(sticks[i]==sticks[i-1] && sticks[i-1]==sticks[i-2] && sticks[i-2]==sticks[i])
            {
                vector<int>arr(3);
                arr[0]=sticks[i];
                arr[1]=sticks[i-1];
                arr[2]=sticks[i-2];
                f=1;
                    for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
                break;
            }
            }
            if(f==0)
            {
                if(sticks[2] < (sticks[1]+sticks[0]))
            {
                vector<int>arr(3);
                arr[0]=sticks[0];
                arr[1]=sticks[1];
                arr[2]=sticks[2];
                for(int i=0;i<arr.size();i++)
                {
                   cout<<arr[i]<<" ";
                }
            }
            else if(sticks[0]==sticks[1] && sticks[1]==sticks[2] && sticks[2]==sticks[0])
            {
                vector<int>arr(3);
                arr[0]=sticks[0];
                arr[1]=sticks[1];
                arr[2]=sticks[2];
                        for(int i=0;i<arr.size();i++)
                        {
                        cout<<arr[i]<<" ";
                        }
            }
            else 
            {
                vector<int>arr(1);
                arr[0]=-1;
                    for(int i=0;i<arr.size();i++)
                    {
                    cout<<arr[i]<<" ";
                    }   
            }
            }
        }
    return 0;
}

