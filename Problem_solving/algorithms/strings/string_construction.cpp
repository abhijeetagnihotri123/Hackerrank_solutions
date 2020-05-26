#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
map<char,int>m;
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        m[s.at(i)]++;
    }
    for(char ch='a';ch<='z';ch++)
    {
        if(m[ch]!=0)
        {
            c++;
        }
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

