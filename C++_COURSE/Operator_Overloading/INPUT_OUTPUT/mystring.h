#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <cstring>
using namespace std;

class mystring
{
    friend ostream &operator<<(ostream &,mystring &);
    friend istream &operator>>(istream &,mystring &);
    private:
        char *str;
    public:
    mystring();
    mystring(char *);
    mystring(const mystring&);
    ~mystring();

    mystring &operator=(const mystring &);
    mystring &operator=(mystring &&);

    void display(void) const;
    int get_length(void) const;
    char *get_str(void) const;
};

#endif