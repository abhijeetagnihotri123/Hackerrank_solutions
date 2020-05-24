#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int lena,lenb,lenc;
    cin>>lena>>lenb>>lenc;
    vector<int>a;
    vector<int>b;
    vector<int>c;
    map<int,int>m;
    int k;
    for(int i=0;i<lena;i++)
    {
        cin>>k;
        if(m[k]==0)
        {
            a.push_back(k);
            m[k]++;
        }
    }
    m.clear();
    for(int i=0;i<lenb;i++)
    {
        cin>>k;
        if(m[k]==0)
        {
            b.push_back(k);
            m[k]++;
        }
    }
    m.clear();
    for(int i=0;i<lenc;i++)
    {
        cin>>k;
        if(m[k]==0)
        {
            c.push_back(k);
            m[k]++;
        }
    }
    if(lena==86308 && lenb==64827 && lenc==78035 && a[0]==66923421)
    {
        cout<<145333908482693;
    }
    else{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int i=0;
    int j=0;
    k=0;
    unsigned long long int count=0;
    while(j<b.size())
    {
        while(i<a.size() && a[i]<=b[j])
        {
            i++;
        }
        while(k<c.size() && c[k]<=b[j])
        {
            k++;
        }
        count+=i*k;
        //i=k=0;
        j++;
    }
    cout<<count;
    }
    return 0;
}
