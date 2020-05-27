#include <bits/stdc++.h>

using namespace std;

int count(int,int,int);
int powerSum(int X, int N) {
    int c=0;
    int m=ceil(pow(X,1.0/N));
    if(pow(m,N)==X)
    {
        c=1;
    }
    m=m-1;
    return count(X,N,m)+c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
int count(int X,int n,int m)
{
    if(X==0)
    {
        return 1;
    }
    else if(X<0 || m<=0)
    {
        return 0;
    }
    else
    {
        return count(X-pow(m,n),n,m-1) + count(X,n,m-1);
    }
}

