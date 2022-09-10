#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{   
    std::cout << std::boolalpha;    // change to true/false
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;

    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Default  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "Default  (10 == 20) : " << (10 == 20)  << std::endl;
    return 0;
}