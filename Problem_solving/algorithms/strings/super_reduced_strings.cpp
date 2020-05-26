#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s)
{
    string str="";
    for(unsigned int i=1;i<s.length();++i)
    {
        if(s.at(i-1)==s.at(i))
        {
            s.erase(i-1,2);
            str=s;
            i=0;
        }
    }
    if(s.length()==0)
    {
        str="Empty String";
    }
    return str;
}
int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}

