#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string MostFrequent(string,vector<string>&);


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        cin.ignore();
        string paragraph; 
        getline(cin,paragraph);
        int n;
        cin>>n;
        vector<string> taboo(n);
        for (int i = 0; i < n; ++i)
            cin>>taboo[i];
        cout << MostFrequent(paragraph, taboo)<<endl; 
    } 
    return 0; 
}
string MostFrequent(string paragraph,vector<string>&taboo)
{
    unordered_map<string,bool>um;
    unordered_map<string,int>freq;
    int n = paragraph.length();
    int m = taboo.size();
    int i,j;
    i = j = 0;
    string str="";
    while(i<n && j<m)
    {   
        um[taboo[j++]]=true;
        if(!((paragraph[i]>='A' && paragraph[i]<='Z') || (paragraph[i]>='a' && paragraph[i]<='z')))
        {
            if(str.length()>0)
            {
                freq[str]++;
            }
            str="";
        }
        else
        {
            if(paragraph[i]>='A' && paragraph[i]<='Z')
            {
                paragraph[i]+=32;
            }
            str+=paragraph[i];
        }
        i++;
    }
    while(i<n)
    {
        if(!((paragraph[i]>='A' && paragraph[i]<='Z') || (paragraph[i]>='a' && paragraph[i]<='z')))
        {
            if(str.length()>0)
            {
                freq[str]++;
            }
            str="";
        }
        else
        {
            if(paragraph[i]>='A' && paragraph[i]<='Z')
            {
                paragraph[i]+=32;
            }
            str+=paragraph[i];
        }
        i++;
    }
    if(str.length()>0)
    {
        freq[str]++;
    }
    while(j<m)
    {
        um[taboo[j++]]=true;
    }
    int max_freq = -2147483648;
    string result;
    for(auto it = freq.begin();it!=freq.end();it++)
    {   
        if(!um[it->first])
        {
            if(it->second > max_freq)
            {
                max_freq = it->second;
                result = it->first;
            }
        }
    }
    return result;
}