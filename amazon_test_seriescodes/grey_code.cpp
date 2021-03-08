#include <bits/stdc++.h>
using namespace std;

vector<string> generateCode(int);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string>res = generateCode(n);
        for(string x : res)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
string convert(int &x,int &n)
{
    string str="";
    int c = 0;
    int a;
    while(x>0)
    {
        int a = x>>1;
        a = a<<1;
        a = x-a;
        str += (char)(a+48);
        x = x>>1;
        c++;
    }
    for(int i=0;i<n-c;i++)
    {
        str+='0';
    }
    reverse(str.begin(),str.end());
    return str;
}
vector<string> generateCode(int n)
{
    int N = (1<<n);
    int x;
    vector<string>v;
    for(int i=0;i<N;i++)
    {
        x = i ^ (i>>1);
        string binary = convert(x,n);
        v.push_back(binary);
    }
    return v;
}