#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    int matrix[6][6];
    for(int i = 0;i < 6;i++) {
        for(int j = 0;j < 6;j++) {
             cin>>matrix[i][j];
        }
    }
    int maxsum = -1000,jj = 0;
    for(int i = 0;i < 4;i++) {
        int sum = 0;
        for(int j = jj;j < jj+3;j++) {
            sum += matrix[i][j];
            if(j==jj) sum += matrix[i+1][jj+1];
            sum += matrix[i+2][j];
        }
        jj = (jj < 3) ? jj+1 : 0;
        if(sum > maxsum) maxsum = sum;
        if(jj != 0) i--;
    }
    cout<<maxsum;
    return 0;
}

