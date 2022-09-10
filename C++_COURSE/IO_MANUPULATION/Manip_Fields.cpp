#include <iostream>
#include <iomanip>

using namespace std;

void ruler()
{
    cout << "12345678901234567890123456789012345678901234567890" << endl;
}
int main()
{   
    ruler();
    int num1{1234};
    double num2{1234.5678};
    cout<<num1<<endl<<num2<<endl;
    ruler();
    cout<<setw(10)<<num1<<endl<<setw(10)<<num2<<endl;
    return 0;
}