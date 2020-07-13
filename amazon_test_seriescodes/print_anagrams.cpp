#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>Anagrams(vector<string>& string_list) 
{
    map<string,bool>m;
    map<string,int>index_map;
    int n = string_list.size();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        string s = string_list[i];
        sort(s.begin(),s.end());
        if(!m[s])
        {
            m[s]=true;
            index_map[s]=count;
            count++;
        }
    }
    vector<vector<string>>result(count);
    for(auto it = m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<end;
    }
    for(auto it = index_map.begin();it!=index_map.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return result;
}
int main()
{   
    int n;
    cin>>n;
    vector<string>input(n);
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    vector<vector<string>>anagrams = Anagrams(input);
    return 0;   
}