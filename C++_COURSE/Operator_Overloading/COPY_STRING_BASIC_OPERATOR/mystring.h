#ifndef _MYSTRING_H_
#define _MYSTRING_J_
#include <cstring>
#include <iostream>
class mystring
{
    private:
        char *str;
    public:
        mystring();
        mystring(const char*s);
        mystring(const mystring &);
        ~mystring();
        mystring &operator=(const mystring &);
        void display() const;
        int get_length() const;
        const char *get_str() const;
};

#endif