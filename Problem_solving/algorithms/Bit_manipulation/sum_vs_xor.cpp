#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
long solve(long n) {
    
    int c=0;
    while(n>0)
    {
        if(n%2==0)
        {
            c++;
        }
        n=n/2;
    }
    return pow(2,c);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = solve(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

