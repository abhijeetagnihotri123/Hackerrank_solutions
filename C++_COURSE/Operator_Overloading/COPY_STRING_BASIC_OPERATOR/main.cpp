#include "mystring.h"

int main()
{   
    mystring a("Hello");
    a.display();
    mystring b;
    b = a;
    b.display();
    return 0;
}