#include <bits/stdc++.h>

using namespace std;
bool check_anagram(string&,string&);
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string str) {
        int n =str.length();
        string s1;
        int c=0;
        vector<string>s;
        map<string,int>m;
        for(int len=1;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {   
                s1=str.substr(i,len);
                sort(s1.begin(),s1.end());
                m[s1]++;
            }
        }
        for(auto it=m.begin();it!=m.end();it++)
        {   
            int n = it->second;
            c+=n*(n-1)/2;
        }
    return c;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
bool check_anagram(string &s1,string &s2)
{
    map<char,int>m;
    int n = s1.length();
    for(int i=0;i<n;i++)
    {
        m[s1[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        m[s2[i]]--;
    }
    int c = 0;
    for(char ch = 'a';ch<='z';ch++)
    {
        if(m[ch]==0)
        {
            c++;
        }
    }
    return c==26;
}
