#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool keypair(vector<int> array, int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        for (int i = 0; i < n; i++) cin >> array[i];
            cout << (keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
bool keypair(vector<int> a,int N,int X)
{
    unordered_map<int,int>m;
    bool flag = false;
    for(int i=0;i<N;i++)
    {
        m[a[i]]++;
    }
    for(int i=0;i<N;i++)
    {
        if(m[X-a[i]]==1 && (X-a[i])==a[i])
        {   
            continue;
        }
        else if(m[X-a[i]]>1 && (X-a[i]) == a[i])
        {       
            flag = true;
            break;
            //cout<<"Here2"<<endl;
        }
        else if(m[X-a[i]]>=1 && (X-a[i]) != a[i])
        {   
            flag = true;
            break;
            //cout<<"Here3"<<endl;
        }
    }
    return flag;
}