#include <iostream>
using namespace std;

int main()
{   
    short int word = 0x0001;
    char *byte = (char*)&word;
    if(byte[0])
    {
        cout<<"LITTLE ENDIAN"<<endl;
    }
    else
    {
        cout<<"BIG ENDIAN"<<endl;
    }
    return 0;
}