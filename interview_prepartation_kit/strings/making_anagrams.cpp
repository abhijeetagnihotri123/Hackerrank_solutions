#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char,int>m1;
    map<char,int>m2;
    for(int i=0;i<a.length();i++)
    {
        m1[a[i]]++;
    }
    for(int i=0;i<b.length();i++)
    {
        m2[b[i]]++;
    }
    int s=0;
    for(char ch='a';ch<='z';ch++)
    {
        s+=abs(m1[ch]-m2[ch]);
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
