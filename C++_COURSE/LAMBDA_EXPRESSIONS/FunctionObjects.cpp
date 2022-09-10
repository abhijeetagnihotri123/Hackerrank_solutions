#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Square_Functor
{
    void operator()(int x)
    {
        cout<<x*x<<" ";
    }
};

struct Person
{
    string name;
    int age;
    Person(string name,int age)
    {
        this->name = name;
        this->age = age;
    }
};

template<typename T>
struct Displayer
{
    void operator()(const T &data)
    {
        cout<<"Display Functor "<<data<<endl;
    }
};


class Multiplier
{
    private:
        int num{};
    public:
        Multiplier(int n):num{n}{}
        int operator()(int mul)
        {
            return num*mul;
        }
};

ostream &operator<<(ostream &os,const Person &k)
{
    os<<k.name<<" "<<k.age;
    return os;
}

int main()
{       
    Square_Functor square;
    vector<int> vec1 {1,2,3,4,5};
    Displayer<int>d;
    for_each(vec1.begin(),vec1.end(),d);
    for_each(vec1.begin(),vec1.end(),[](int x){cout<<x<<" ";});
    
    Multiplier mul(100);
    cout<<endl;
    cout<<mul(9801)<<endl;

    //transform(vec1.begin(),vec1.end(),vec1.begin(),mul);
    for_each(vec1.begin(),vec1.end(),d);
    return 0;
}