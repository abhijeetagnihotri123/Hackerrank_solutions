#include "mystring.h"
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

mystring::mystring(void)
    :str{nullptr}
{
    str = new char[1];
    *str = '\0';
}
mystring::mystring(const char *s)
    :str{nullptr}
{
    if(s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }
}
mystring::mystring(const mystring &s)
    :str{nullptr}
{
    str = new char[std::strlen(s.str)+ 1];
    std::strcpy(str, s.str);
    std::cout << "Copy constructor used" << std::endl;
}
mystring::~mystring()
{
    delete(str);
}
mystring& mystring::operator=(const mystring &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    delete(str);
    str = new char[strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;
}
mystring mystring::operator-() const {
    char *buff= new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concatentate
mystring mystring::operator+(const mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    mystring temp {buff};
    delete [] buff;
    return temp;
}
bool mystring::operator==(const mystring &rhs)
{
    return (strcmp(str,rhs.str) == 0);
}
const char *mystring::get_str() const {return str;}
int mystring::get_length()const
{
    return strlen(str);
}
void mystring::display() const
{
    cout<<str<<" : "<<get_length()<<endl;
}