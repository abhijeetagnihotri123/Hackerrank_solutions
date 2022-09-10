#include <iostream>
#include <fstream>

using namespace std;

int main()
{   
    ifstream fin{"poem.txt"};
    if(fin)
    {
        cout<<"OK\n";
    }
    string line;
    while(getline(fin,line))
    {
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}