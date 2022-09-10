#include <iostream>
#include <string>
#include <vector>
#include <functional>   // for std::function
#include <algorithm>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &,const Person &);
    private:
        string name;
        int age;
    public:
        Person(string name,int age):name{name},age{age}{};
        Person(const Person &p):name{p.name},age{p.age}{};
        ~Person() = default;
        string get_name() const { return name; }
        void set_name(std::string name) {this->name = name; };
        int get_age() const {return age; }
        void set_age(int age) {this->age = age;}
};
ostream &operator<<(ostream &os, const Person &rhs) 
{
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}
void test1()
{
    cout<<"Test1\n";
    [](){cout<<"Hi\n";}();
    [](int x){cout<<(x<<1)<<endl;}(99);
    [](int x,int y){cout<<(x+y)<<endl;}(100,230);
}
void test2()
{
    cout<<"Test2\n";
    auto l1 = [](){cout<<"Hi from lambda test2\n";};
    l1();
    int num1{100};
    int num2{100};
    auto l2 = [](int x,int y){cout<<(x+y)<<endl;};
    l2(10,20);
    auto l3 = [](int &x, int y) {
        cout << "x: " << x << " y: " << y << endl;
        x = 1000;
        y = 2000;
    };
    
    l3(num1, num2);
    cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}
void test3()
{
    cout<<"Test3\n";
    auto l = [](Person p){cout<<p<<endl;};
    l(Person("Akshay",28));
}
void filter_vector(vector<int>&vec,function<bool(int)>func)
{   
    cout<<"[ ";
    for(int &x : vec)
    {   
        if(func(x))
        {
            cout<<x<<" ";
        }
    }
    cout<<"]\n";
}
void test4()
{
    cout<<"Test4\n";
    vector<int> nums {10,20,30,40,50,60,70,80,90,100};
    filter_vector(nums, [](int x) {return x>50;});
    filter_vector(nums,[](int x){return x<=30;});
}
void test5()
{
    
}
int main()
{   
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}