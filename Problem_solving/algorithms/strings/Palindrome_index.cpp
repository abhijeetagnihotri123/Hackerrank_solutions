#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {

    int n=s.length();
    //bool flag=false;
    int result=-1;
    for(int i=0;i<=n/2;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            if(s[i+1]==s[n-i-1] && s[i+2]==s[n-i-2])
            {
                result=i;
                //flag=true;  
                break;
            }
            else if(s[i]==s[n-i-2] && s[i+1]==s[n-3-i])
            {
                result=n-i-1;
                //flag=true;
                break;
            }
        }
    }
    return result;
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

