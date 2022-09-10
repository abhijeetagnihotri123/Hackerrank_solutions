#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string str;
    int x;
    double y;
    string info = "HELLO_FROM_STRING_STREAM 100 100.984";
    stringstream ss(info);
    ss>>str>>x>>y;
    cout<<str<<" "<<x<<" "<<y<<endl;
    std::ostringstream oss {};
    oss << std::setw(10) << std::left << str
          << std::setw(5) << x
          << std::setw(10) << y << std::endl;
    std::cout << oss.str();

    int value;
    string entry;
    bool flag = false;
    do
    {   
        cin>>entry;
        istringstream validator(entry);
        if(validator>>value)
        {
            flag = true;
        }
        else
        {
            cout<<"Enter a valid Integer\n";
        }
    } while (!flag);
    
    return 0;
}