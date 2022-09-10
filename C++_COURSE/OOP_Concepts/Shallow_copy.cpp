// This program is designed to crash to illustrate drawbacks of shallow copy

#include <iostream>
#include <string>

using namespace std;

class Shallow
{
    private:
        int *data;
    public:
    void set_data(int d){*data = d;}
    int get_data(){return *data;}
    Shallow(void);
    Shallow(int);
    Shallow(const Shallow&);
    ~Shallow();
};
Shallow::Shallow(void)
{   
    cout<<"Default Constructor"<<endl;
    data = new int;
    *data = 0;
}
Shallow::Shallow(int d)
{       
    cout<<"Parameterized Constructor"<<endl;
    data = new int;
    *data = d;
}
Shallow::Shallow(const Shallow &source)
    :data{source.data}
{
    cout<<"Copy Constructor to copy pointer "<<source.data<<endl;
}
Shallow::~Shallow()
{   
    cout<<"Destructor Freeing Data "<<data<<endl;
    delete data;
}

void display(Shallow s)
{   
    cout<<"In Function Call"<<endl;
    cout<<s.get_data()<<endl;
    cout<<"Leaving Function call"<<endl;
}

int main()
{   
    Shallow obj1 {100};
    display(obj1);
    
    Shallow obj2 {obj1};
    obj2.set_data(1000);
    return 0;
}