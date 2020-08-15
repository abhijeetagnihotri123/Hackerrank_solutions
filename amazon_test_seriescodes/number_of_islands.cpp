#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}
void mark_current(vector<int>A[],int r,int c,int i,int j)
{
    if(i<0 || i>=r || j<0 || j>=c || A[i][j] != 1)
    {
        return;
    }
    else
    {
        A[i][j] = 0;
        mark_current(A,r,c,i-1,j);
        mark_current(A,r,c,i+1,j);
        mark_current(A,r,c,i,j-1);
        mark_current(A,r,c,i,j+1);
        mark_current(A,r,c,i-1,j-1);
        mark_current(A,r,c,i-1,j+1);
        mark_current(A,r,c,i+1,j-1);
        mark_current(A,r,c,i+1,j+1);
    }
}
int findIslands(vector<int>A[],int N,int M)
{   
    int num_islands;
    if(N == 0)
    {
        num_islands = 0;
    }
    else
    {   
        int i,j;
        i = j = 0;
        num_islands = 0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
               if(A[i][j] == 1)
                {
                    mark_current(A,N,M,i,j);
                    num_islands++;
                }
            }
        }
    }
    return num_islands;
}