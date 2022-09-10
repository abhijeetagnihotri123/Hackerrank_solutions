#include <iostream>
#include <iomanip>

using namespace std;

int main()
{   
    double num1 {123456789.987654321};
    double num2 {1234.5678};                     
    double num3 {1234.0};
    
    cout << "--Defaults ----------------------------" << endl;
    cout << num1 << endl;	
    cout << num2<< endl;	
    cout << num3<< endl;

    cout<<setprecision(2)<<"Precision 2\n";
    cout << num1 << endl;	
    cout << num2<< endl;	
    cout << num3<< endl;

    cout<<setprecision(5)<<"Precision 5\n";    
    cout << num1 << endl;	
    cout << num2<< endl;	
    cout << num3<< endl;
    return 0;
}