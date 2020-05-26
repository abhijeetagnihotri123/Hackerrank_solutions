#include <bits/stdc++.h>

using namespace std;
string trimmedstring(string);
int gemstones(vector<string>arr)
{
    int n;
    n=arr.size();
    for(int i=0;i<n;i++)
    {
        arr[i]=trimmedstring(arr[i]);
    }
    map<char,int>m;
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i].length();j++)
        {
            m[arr[i].at(j)]++;
        }
    }
    for(char ch='a';ch<='z';ch++)
    {
        if(m[ch]==n)
        {
            c++;
        }
    }
    return c;
}
string trimmedstring(string s)
{
    string result="";
    vector<int>v(s.length());
    map<int,int>m;
    for(int i=0;i<s.length();i++)
    {
        m[(int)s.at(i)]++;
        v[i]=(int)s.at(i);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<s.length();i=i+m[v[i]])
    {
        result=result+(char)v[i];
    }
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

