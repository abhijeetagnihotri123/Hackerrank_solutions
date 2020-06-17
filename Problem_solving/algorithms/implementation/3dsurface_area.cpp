#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {

    int area = 0;
    int t,b,l,r,u,d;
    int cur;
    int n = A.size();
    int m = A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {   
            t=b=l=r=u=d=0;
            cur = A[i][j];
            if(cur!=0)
            {
                t++;
                b++;
            }
            if(i-1 >= 0)
            {
                if(cur > A[i-1][j])
                {
                    u = cur - A[i-1][j];
                }
            }
            else 
            {
                u = cur;
            }
            if(i+1 < n)
            {
                if(cur > A[i+1][j])
                {
                    d = cur - A[i+1][j];
                }
            }
            else
            {
                d = cur;
            }
            if(j-1>=0)
            {
                if(cur > A[i][j-1])
                {
                    l = cur - A[i][j-1];
                }
            }
            else
            {
                l = cur;
            }

            if(j+1<m)
            {
                if(cur > A[i][j+1])
                {
                    r = cur - A[i][j+1];
                }
            }
            else
            {
                r = cur;
            }
            area = area + t + b + l + r + u + d;
        }
    }
    return area;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
