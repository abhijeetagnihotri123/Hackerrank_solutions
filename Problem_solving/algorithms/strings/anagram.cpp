#include <bits/stdc++.h>
using namespace std;
int anagram(string s)
{
    int n=s.length();
    int c=0;
    switch(n%2)
    {
    case 1:
        c=-1;
        break;
    case 0:
        map<char,int>m;
        for(char ch='a';ch<='z';ch++)
        {
            m[ch]=0;
        }
        for(int i=0;i<n/2;i++)
        {
            m[s.at(i)]++;
        }
        for(int i=n/2;i<n;i++)
        {
            m[s.at(i)]--;
        }
        for(char ch='a';ch<='z';ch++)
        {
            if(m[ch]>0)
            {
                c+=m[ch];
            }
        }
    }
    return c;
}
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagram(s);
        cout << result << endl;
    }
    return 0;
}

