#include <bits/stdc++.h>
using namespace std;

vector<int>spans(vector<int>&,int&);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int>prices(N,0);
        vector<int>s;
        for(int i=0;i<N;i++)
        {
            cin>>prices[i];
        }
        s = spans(prices,N); 
        for(int x : s)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
vector<int>spans(vector<int>&prices,int &n)
{
    vector<int>s(n);
    s[0] = 1;
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(!st.empty() && prices[st.top()] <= prices[i])
        {
            st.pop();
        }
        s[i] = st.empty()?(i+1):(i-st.top());
        st.push(i);
    }
    return s;
}