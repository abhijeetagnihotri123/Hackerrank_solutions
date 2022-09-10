#include "mystring.h"
#include <iostream>
using namespace std;

int main()
{   
    mystring larry{"Larry"}; 
    mystring moe{"Moe"};
    
    mystring stooge = larry;
    larry.display();                                                                      // Larry
    moe.display();                                                                      // Moe
    
    cout << (larry == moe) << endl;                                         // false
    cout << (larry == stooge) << endl;                                      // true

    larry.display();                                                                    // Larry
    mystring larry2 = -larry;
    larry2.display();                                                                    // larry
     
    mystring stooges = larry + "Moe";                                     // ok with member function
    //Mystring stooges = "Larry" + moe;                                 // Compiler error
    
    mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();      
                                                   // Moe Larry
    mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();          
    return 0;
}