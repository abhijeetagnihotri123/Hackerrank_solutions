#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class mystring {
    friend bool operator==(const mystring &lhs, const mystring &rhs);
    friend mystring operator-(const mystring &obj);
    friend mystring operator+(const mystring &lhs, const mystring &rhs);
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    mystring();
    mystring(const char *s);
    mystring(const mystring &source);
    mystring( mystring &&source);
    ~mystring();
    
    mystring &operator=(const mystring &rhs);
    mystring &operator=(mystring &&rhs);
   
    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif // _MYSTRING_H_
