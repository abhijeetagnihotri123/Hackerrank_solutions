#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pangrams function below.
 */
string pangrams(string str) {
    
    string result="";
    int n=str.length();
    if(n<26)
    {
        result="not pangram";
    }
    else
    {
        map<char,int>m;
        for(char ch='a';ch<='z';ch++)
        {
            m[ch]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(str.at(i)>='A'&&str.at(i)<='Z')
            {
                str.at(i)+=32;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(str.at(i)==' ')
            {
                continue;
            }
           else
           {
               m[str.at(i)]++;
           }
        }
        int c=0;
        for(char ch='a';ch<=122;ch++)
        {
            if(m[ch]!=0){c++;}
        }
        if(c==26){result="pangram";}
        else{result="not pangram";}
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

