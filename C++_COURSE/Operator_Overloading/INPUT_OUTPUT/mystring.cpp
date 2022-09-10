#include "mystring.h"
using namespace std;

mystring::mystring()
    :str{nullptr}
{
    str = new char[1];
    *str = '\0';
}
mystring::mystring(char *s)
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
        str = new char[strlen(source.str)+1];
        strcpy(str,source.str);
    }
}
mystring::~mystring(){   
    delete [] str;
    cout<<"Destroying object"<<endl;
}
int mystring::get_length() const{return strlen(str);}
char *mystring::get_str() const{return str;}
void mystring::display() const{
    cout<<str<<" : "<<get_length()<<endl;
}

ostream &operator<<(ostream &os,mystring &rhs)
{
    os<<rhs.str;
    return os;
}
istream &operator>>(istream &in,mystring &rhs)
{
    char *buff = new char[1000];
    in>>buff;
    rhs = mystring(buff);
    delete(buff);
    return in;
}
mystring &mystring::operator=(const mystring &rhs)
{
    cout<<"Copy assigment"<<endl;
    if(this == &rhs)
    {
        return *this;
    }
    delete(str);
    str = new char[strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;
}
mystring &mystring::operator=( mystring &&rhs) {
    cout << "Using move assignment" <<endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}
