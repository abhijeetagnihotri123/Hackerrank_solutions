#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{       
    ifstream fin("poem.txt");
    ofstream fout;
    fout.open("poem_out.txt");
    if(!fin)
    {
        cout<<"File successfully opened\n";
    }
    char c;
    while(fin.get(c))
    {
        fout.put(c);
    }
    cout<<"File Copied\n";
    fin.close();
    fout.close();
    return 0;
}
