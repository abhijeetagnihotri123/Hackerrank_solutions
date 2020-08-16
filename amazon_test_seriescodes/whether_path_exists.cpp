#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
}
struct cell
{
    int type;
    int x;
    int y;
};
bool is_possible(vector<vector<int>> &M,int n)
{
    bool result = false;
    cell current;
    cell temp;
    queue<cell>q;
    int i,j,type;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(M[i][j] == 1)
            {
                M[i][j] = 0;
                current.type = 1;
                current.x = i;
                current.y = j;
                q.push(current);
            }
        }
    }
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current.type == 2)
        {
            result = true;
            break;
        }
        else
        {
            i = current.x;
            j = current.y;
            M[i][j]=0;
            if(i>=1 && M[i-1][j] == 3 || M[i-1][j] == 2)
            {
                temp.x=i-1;
                temp.y=j;
                temp.type=M[i-1][j];
                q.push(temp);
            }
            if(j>=1 && M[i][j-1] == 3 || M[i][j-1] == 2)
            {
                temp.x = i;
                temp.y = j-1;
                temp.type = M[i][j-1];
                q.push(temp);
            }
            if(i<n-1 && M[i+1][j] == 3 || M[i+1][j] == 2)
            {
                temp.x = i+1;
                temp.y = j;
                temp.type = M[i+1][j];
                q.push(temp);
            }
            if(j<n-1 && M[i][j+1] == 3 || M[i][j+1] == 2)
            {
                temp.x = i;
                temp.y = j+1;
                temp.type = M[i][j+1];
                q.push(temp);
            }
        }
    }
    return result;
}