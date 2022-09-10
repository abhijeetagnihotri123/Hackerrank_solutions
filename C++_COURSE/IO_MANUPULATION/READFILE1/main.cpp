#include <iostream>
#include <fstream>

using namespace std;

int main()
{   
    ifstream fin{"test.txt"};
    if(!fin)
    {
        cerr<<"Cannot Open file\n";
    }
    string str;
    int x;
    double y;
    fin>>str>>x>>y;
    cout<<str<<" "<<x<<" "<<y<<endl;
    fin.close();
    fin.open("test1.txt");
    while(fin>>str>>x>>y)
    {
        cout<<str<<" "<<x<<" "<<y<<endl;
    }
    fin.close();
    return 0;
}