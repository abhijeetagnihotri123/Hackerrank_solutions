#include <bits/stdc++.h>
using namespace std;
int count_ones(string s1,string s2)
{
    int c = 0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i] == '1' || s2[i] == '1')
        {
            c++;
        }
    }
    return c;
}
vector<int> acmTeam(vector<string>topic)
{   
    vector<int>result(2);
    int max_count = 0;
    int ways = 0;
    int n = topic.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp;
            temp = count_ones(topic[i],topic[j]);
            if(temp > max_count)
            {
                max_count = temp;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(count_ones(topic[i],topic[j]) == max_count)
            {
                ways++;
            }
        }
    }
    result[0]=max_count;
    result[1]=ways;
    return result;
}
int main()
{   
    int n,m;
    cin>>n>>m;
    vector<string>topics(n);
    for(int i=0;i<n;i++)
    {
        cin>>topics[i];
    }
    vector<int>result(2);
    result = acmTeam(topics);
    cout<<result[0]<<" "<<result[1];
    return 0;
}