#include <iostream>
#include <cstring>
#include <cctype>
#include "mystring.h"

// No-args constructor
mystring::mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
mystring::mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
mystring::mystring(const mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
mystring::mystring( mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
mystring::~mystring() {
    delete [] str;
}

// Copy assignment operator
mystring &mystring::operator=(const mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
mystring &mystring::operator=( mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *mystring::get_str() const { return str; }


// Equality
bool operator==(const mystring &lhs, const mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Make lowercase
mystring operator-(const mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i<std::strlen(buff); i++) 
        buff[i] = std::tolower(buff[i]);
    mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concatenation
mystring operator+(const mystring &lhs, const mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    mystring temp {buff};
    delete [] buff;
    return temp;
}






