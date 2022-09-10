#include <iostream>

using namespace std;

int main()
{   
    int miles{};
    int gallons{};
    double mile_per_gallon;
    cout<<"Enter number of miles\n";
    cin>>miles;
    cout<<"Enter number of gallons\n";
    cin>>gallons;

    try
    {
        if(gallons == 0)
        {
            throw 0;
        }
        mile_per_gallon = static_cast<double>(miles)/gallons;
        cout<<"Result: "<<mile_per_gallon<<endl;
    }
    catch(int &e)
    {   
        cout<<"Cannot divide by zero\n";
        cerr << e << endl;
    }
    cout<<"Program Executed Successfully\n";
    return 0;
}