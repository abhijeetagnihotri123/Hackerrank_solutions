#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class mystring
{
    private:
        char *str;
    public:
        mystring(void);
        mystring(const char *);
        mystring(const mystring&);
        ~mystring();

        mystring& operator=(const mystring&);
        bool operator==(const mystring &);
        mystring operator-() const;                             // make lowercase
        mystring operator+(const mystring &rhs) const;
        void display(void) const;
        int get_length(void) const;
        const char *get_str(void) const;
};

#endif