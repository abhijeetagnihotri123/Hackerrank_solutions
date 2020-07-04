#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    int left,right,up,down,upright,downright,upleft,downleft;
    left = c_q-1;
    right = n - c_q;
    up = n-r_q;
    down = r_q - 1;
    upleft = left < up ? left : up;
    upright = right < up ? right : up;
    downleft = down >= left ? left : down;
    downright = down >= right ? right : down;
    int N = obstacles.size();
    for(int i=0;i<N;i++)
    {
        int row = obstacles[i][0];
        int col = obstacles[i][1];
        if (row == r_q && col < c_q)
        {
            if(c_q-col-1 < left)
            {
                left = c_q - col - 1;
            }
        }
        else if (row == r_q && col > c_q)
        {
            if(col-c_q-1 < right)
            {
                right = col - c_q - 1;
            }
        }
        else if (row > r_q && col == c_q)
        {
            if(row-r_q-1 < up)
            {
                up = row-r_q-1;
            }
        }
        else if (row < r_q && col == c_q)
        {
            if(r_q-row-1 < down)
            {
                down = r_q-row-1;
            }
        }
        else if(row > r_q && col < c_q)
        {
            if(row-r_q == c_q-col)
            {
                if(row-r_q-1<upleft)
                {
                    upleft = row-r_q-1;
                }
            }
        }
        else if(row > r_q && col>c_q)
        {
            if(row-r_q == col-c_q)
            {
                if(row-r_q-1<upright)
                {
                    upright = row-r_q-1;
                }
            }
        }
        else if(row<r_q && col<c_q)
        {
            if(r_q-row == c_q-col)
            {
                if(r_q-row-1<downleft)
                {
                    downleft=r_q-row-1;
                }
            }
        }
        else if(row<r_q && col>c_q)
        {
            if(r_q-row == col-c_q)
            {
                if(r_q-row-1<downright)
                {
                    downright=r_q-row-1;
                }
            }
        }
    }
    int attack = (up+down+left+right+upleft+upright+downleft+downright);
    return attack;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
