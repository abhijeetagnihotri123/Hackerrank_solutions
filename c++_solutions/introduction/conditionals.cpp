#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string a[9]={"one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    if(n>9)
    {cout<<"Greater than 9";}
    else
    {cout<<a[n-1];}
   return 0;
}

