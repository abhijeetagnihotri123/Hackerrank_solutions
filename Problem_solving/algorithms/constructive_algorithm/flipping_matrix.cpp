#include <bits/stdc++.h>

using namespace std;

int max(int a,int b)
{
    return a>=b ? a:b;
}
int flippingMatrix(vector<vector<int>> matrix) {

    int n = matrix.size()/2;
    int m = matrix.size();
    int sum=0;
        for(int i=0;i<n;i++)
        {   
            int Max;
            for(int j=0;j<n;j++)
            {
                int m = 2*n;
                int max1 = max(matrix[i][j],matrix[m-i-1][j]);
                int max2 = max(matrix[i][j],matrix[i][m-j-1]);
                int max3 = max(matrix[i][j],matrix[m-i-1][m-j-1]);
                int max4 = max(max1,max2);
                Max = max(max4,max3);
                sum+=Max;
            }
        }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> matrix(2*n);
        for (int i = 0; i < 2*n; i++) {
            matrix[i].resize(2*n);

            for (int j = 0; j < 2*n; j++) {
                cin >> matrix[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
