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
    int n,k,E=100;
    cin>>n>>k;
    int c[n];
   int i=0;
    while(i<n)
        {
        cin>>c[i];
        i++;
    }  for(int i=0;i<n;i+=k)
        {
        if(c[i]==1)
            E=E-3;
        else if(c[i]==0)
            E=E-1;
    }
    cout<<E;
}


