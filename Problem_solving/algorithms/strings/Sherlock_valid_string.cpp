#include <bits/stdc++.h>

using namespace std;
string trim(string s)
{
    map<char,int>m;
    string str="";
    for(int i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(m[s[i]]!=0)
        {
            str+=s[i];
            m[s[i]]=0;
        }
    }
    return str;
}

string isValid(string s)
{
    string result="";
    map<char,int>m;
    for(int i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
    s=trim(s);
    int n=s.length();
    map<int,int>m1;
    for(int i=0;i<n;i++)
    {
        m1[m[s[i]]]++;
    }
    if(m1.size()==1)
    {
        result="YES";
    }
    else if(m1.size()==2)
    {
        map<int,int>::iterator it1,it2,it3,it4;
        it1=m1.begin();
        it2=it1++;
        if(it1->second == n-1 || it2->second == n-1)
        {
        it3=it1->second!=1?it1:it2;
        it4=it1->second==1?it1:it2;
            if((it4->first-it3->first)==1)
            {
                result="YES";
            }
            else if(it4->first==1)
            {
                result="YES";
            }
            else
            {
                result="NO";
            }
        }
        else
        {
            result="NO";        
        }
    }
    else
    {
        result="NO";
    }
    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

