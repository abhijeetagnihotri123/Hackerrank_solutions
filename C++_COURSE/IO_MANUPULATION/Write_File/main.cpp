#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{   
    ofstream fout{"output.txt"};
    string line;
    getline(cin,line);
    fout<<line;
    fout.close();
    return 0;
}