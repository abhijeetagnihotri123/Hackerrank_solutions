#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std; 
string MostFrequent(string paragraph, vector<string> taboo) ;
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
string MostFrequent(string paragraph,vector<string>taboo)
{
    vector<string>para;
    string str = "";
    unordered_map<string,bool>um;
    unordered_map<string,int>freq;
    int i,j,n,m;
    i = j = 0;
    n = paragraph.length();
    m = taboo.size();
    while(i<n && j<m)
    {
        um[taboo[j]]=true;
        if(paragraph[i] == '.' || paragraph[i] == ',' || paragraph[i] == ' ')
        {
            para.push_back(str);
            str = "";
        }
        else
        {
            if(paragraph[i]>='A' || paragraph[i]<='Z')
            {
                paragraph[i]+=32;
            }
            str+=paragraph[i];
        }
        str+=paragraph[i];
        i++;
        j++;
    }
    while(i<n)
    {
        if(paragraph[i] == '.' || paragraph[i] == ',' || paragraph[i] == ' ')
        {
            para.push_back(str);
            str = "";
        }
        else
        {
            if(paragraph[i]>='A' || paragraph[i]<='Z')
            {
                paragraph[i]+=32;
            }
            str+=paragraph[i];
        }
        i++;
    }
    para.push_back(str);
    while(j<m)
    {
        um[taboo[j]]=true;
        j++;
    }
    cout<<um.size();
    for(string s : para)
    {
        cout<<s<<endl;
    }
    return "";
}