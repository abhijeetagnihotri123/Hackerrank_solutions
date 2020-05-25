#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    int a;
    long b;
    char ch;
    float f;
    double d;
    cin>>a;
    cin>>b;
    cin>>ch;
    cin>>f;
    cin>>d;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<ch<<endl;
    cout.setf(ios::fixed);
    cout<<setprecision(3)<<f<<endl;
    cout<<setprecision(9)<<d<<endl;
    return 0;
}

