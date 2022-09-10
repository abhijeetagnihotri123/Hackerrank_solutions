#include "mystring.h"


mystring::mystring()
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
        str = new char[std::strlen(s)+1];
        std::strcpy(str,s);
    }
}
mystring::mystring(const mystring &source)
    :str{nullptr}
{
    if(source.str == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(source.str+1)];
        std::strcpy(str,source.str);
    }
}
mystring::~mystring()
{
    std::cout<<"Destructing object"<<std::endl;
}
mystring &mystring::operator=(const mystring &rhs)
{
    std::cout<<"Overloaded Assignment operator"<<std::endl;
    if(this == &rhs)
    {
        return *this;
    }
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}
// Display method
void mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
 int mystring::get_length() const { return strlen(str); }
 const char *mystring::get_str() const { return str; }


