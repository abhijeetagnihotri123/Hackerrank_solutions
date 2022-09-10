// This program is designed to crash to illustrate drawbacks of shallow copy

#include <iostream>
#include <string>

using namespace std;

class Deep
{
    private:
        int *data;
    public:
    void set_data(int d){*data = d;}
    int get_data(){return *data;}
    Deep(void);
    Deep(int);
    Deep(const Deep&);
    ~Deep();
};
Deep::Deep(void)
{   
    cout<<"Default Constructor"<<endl;
    data = new int;
    *data = 0;
}
Deep::Deep(int d)
{       
    cout<<"Parameterized Constructor"<<endl;
    data = new int;
    *data = d;
}
Deep::Deep(const Deep &source) // delegate constructor to create another pointer 
    :Deep{*source.data} // and copy it's contents
{
    cout<<"Copy Constructor to copy pointer "<<source.data<<endl;
}
Deep::~Deep()
{   
    cout<<"Destructor Freeing Data "<<data<<endl;
    delete data;
}

void display(Deep s)
{   
    cout<<"In Function Call"<<endl;
    cout<<s.get_data()<<endl;
    cout<<"Leaving Function call"<<endl;
}

int main()
{   
    Deep obj1 {100};
    display(obj1);
    
    Deep obj2 {obj1};
    obj2.set_data(1000);
    return 0;
}