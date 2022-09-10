#include "mystring.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    mystring larry {"Larry"};
    larry.display();                                        // Larry
    
    larry = -larry;
    larry.display();                                        // larry
    
    cout << boolalpha << endl;
    mystring moe{"Moe"};
    mystring stooge = larry;
    
    cout << (larry == moe) << endl;             // false
    cout << (larry == stooge) << endl;          // true
        
  //  Mystring stooges = larry + "Moe";   
    mystring stooges = "Larry" + moe;           // Now OK with non-member function
    stooges.display();                                      // LarryMoe
    
    mystring two_stooges = moe + " " + "Larry";     
    two_stooges.display();                               // Moe Larry
    mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                            // Moe larry Curly             
    return 0;
}