#include <bits/stdc++.h>

using namespace std;

int makingAnagrams(string s1,string s2)
{
    int c=0;
    map<char,int>m1;
    map<char,int>m2;
    for(int i=0;i<s1.length();i++)
    {
        m1[s1.at(i)]++;
    }
    for(int i=0;i<s2.length();i++)
    {
        m2[s2.at(i)]++;
    }
    for(char ch='a';ch<='z';ch++)
    {
        c+=abs(m1[ch]-m2[ch]);
    }
    return c;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

