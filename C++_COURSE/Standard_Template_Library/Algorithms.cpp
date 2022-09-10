#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype> 
#include <string>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    public:
        Person() = default;
        Person(string name,int age)
            :name{name},age{age}{}
        bool operator<(const Person &rhs) const
        {
            return this->age < rhs.age;
        }
        bool operator==(const Person &rhs) const
        {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};
void find_test()
{
    cout << "========================" << endl;
    vector<int>v{1,2,3,4,5};
    auto loc = find(v.begin(),v.end(),1);
    if(loc != v.end())
    {
        cout<<"Found the number "<<*loc<<endl;
    }
    list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };
    auto loc1 = find(players.begin(),players.end(),Person{"Moe",20});
    if(loc1 != players.end())
    {
        cout<<"Match Found\n";
    }
}
void count_test()
{
    cout << "========================" << endl;
    vector<int>v{1,2,3,4,5,1,2,1,100};
    int num = count(v.begin(),v.end(),1);
    cout<<num<<endl;
}
void count_if_test() //using lambda's expression
{
    cout << "Using Lambda Expression\n========================" << endl;
    vector<int>v{1,2,3,4,5,1,2,1,100};
    int num;
    num = count_if(v.begin(),v.end(),[](int x){return !(x&1);});
    cout<<num<<" Even numbers are found"<<endl;
    num = count_if(v.begin(),v.end(),[](int x){return (x&1);});
    cout<<num<<" Odd numbers found\n"; 
    num = count_if(v.begin(),v.end(),[](int x){return (x>=5);});
    cout<<num<<" Numbers are bigger than 5\n";
}
void all_of_test()
{
    vector<int> v {1,3,5,7,9,1,3,13,19,5};
    if(all_of(v.begin(),v.end(),[](int x){return x>10;}))
    {
        cout<<"All numbers are not above 10\n";
    }
    if(all_of(v.begin(),v.end(),[](int x){return x<20;}))
    {
        cout<<"All elements are less than 20\n";
    }
}
int main()
{   
    // find_test();
    // count_test();
    // count_if_test();
    all_of_test();
    return 0;
}