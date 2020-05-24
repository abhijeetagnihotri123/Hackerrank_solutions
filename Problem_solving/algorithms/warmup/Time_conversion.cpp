#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
     int h,m,s;
    char ch,hour;
    cin>>h>>ch>>m>>ch>>s>>hour;
    h=(hour=='A')?(h==12?0:h):(h==12?h:h+12);
    cout<<setw(2)<<setfill('0')<<h<<':';
    cout<<setw(2)<<setfill('0')<<m<<':';
    cout<<setw(2)<<setfill('0')<<s<<endl;
    return 0;
}
