#include <bits/stdc++.h>

using namespace std;

// Complete the gridChallenge function below.

bool check_sorted(string a,string b)
{
    int n = a.length();

    for(int i=0;i<n;i++)
    {
        if(a[i] < b[i])
        {
            return true;
        }
    }
    return false;
}
string gridChallenge(vector<string> grid) {

    for(int i=0;i<grid.size();i++)
    {
        sort(grid[i].begin(),grid[i].end());
    }
    bool flag=is_sorted(grid.begin(),grid.end(),check_sorted);
    return flag?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
