#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

void test1()
{
    cout<<"Test1\n";
    vector<int>v{10,20,30,40,50};
    for_each(v.begin(),v.end(),[](int num){
        cout<<num<<" ";
    });
    cout<<endl;
}
void test2()
{
    cout<<"Test2\n";
    struct Point
    {
        int x,y;
    };
    Point pt1{1,2};
	Point pt2{4,3};
	Point pt3{3,5};
	Point pt4{3,1};
	
	vector<Point> triangle1 {pt1,pt2,pt3};
	vector<Point> triangle2 {pt2,pt3,pt1};
	vector<Point> triangle3 {pt1,pt2,pt4};
    if(is_permutation(triangle1.begin(),triangle1.end(),triangle2.begin(),[](Point lhs,Point rhs){
        return lhs.x == rhs.x && lhs.y == lhs.y;}))
    {
        cout<<"Triangle1 and Triangle2 are equivalent!\n";
    }
    else
    {
        cout<<"Triangle1 and Triangle2 are not equivalend!\n";
    }
}
void test3()
{
    cout<<"Test3\n";
    vector<int>v{93,87,73,67,57};
    int bonus_point{5};
    transform(v.begin(),v.end(),v.begin(),[bonus_point](int x){
        return (bonus_point+x);
    });
    for_each(v.begin(),v.end(),[](int x){cout<<x<<" ";});
    cout<<endl;
}
void test4()
{
    cout<<"Test4\n";
    vector<int> nums {1,2,3,4,5};
    nums.erase(remove_if(nums.begin(),nums.end(),[](int num){
        return !(num&1);
    }),nums.end());
    for_each(nums.begin(),nums.end(),[](int num){cout<<num<<" ";});
    cout<<endl;
}
class Person
{   
    friend ostream &operator<<(ostream &,const Person &);
    private:
        int age;
        string name;
    public:
        Person(string name,int age):name{name},age{age}{}
        Person(const Person &p):name{p.name},age{p.age}{}
        Person():Person{"Untitled",0}{}
        Person(string name):Person{name,0}{}
        Person(int age):Person{"Untitled",age}{}
        ~Person() = default;
        string get_name() const { return name; }
        void set_name(std::string name) {this->name = name; };
        int get_age() const {return age; }
        void set_age(int age) {this->age = age; }  
};
ostream &operator<<(ostream &os,const Person &rhs)
{
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}
void test5()
{   
    cout<<"Test5\n";
    Person person1("Larry", 18);
	Person person2("Moe", 30);
	Person person3("Curly", 25);
	vector<Person> people {person1,person2,person3};
    sort(people.begin(),people.end(),[](Person lhs,Person rhs){
        return (lhs.get_age() < rhs.get_age());
    });
    for_each(people.begin(),people.end(),[](Person p){
        cout<<p<<endl;
    });
}
bool in_between(vector<int>&nums,int s,int e)
{
    bool result = all_of(nums.begin(),nums.end(),[s,e](int value){
        return (value >= s && value <= e);
    });
    return result;
}
void test6()
{
    cout << "Test6" << endl;
    cout << std::boolalpha;

    vector<int> nums(10);
    iota(nums.begin(), nums.end(), 1);  
    
    for (int num : nums)
        cout << num << " ";
        
    cout << endl;
    
    cout << in_between(nums, 50, 60) << endl;
    cout << in_between(nums, 1, 10) << endl;
    cout << in_between(nums, 5, 7) << endl;
}
class Password_Validator1
{
    private:
        char restricted_symbol{'$'};
    public:
        bool is_valid(string name)
        {
            return all_of(name.begin(),name.end(),[this](char character){
                return character != restricted_symbol;
            });
        }
};
class Password_Validator2 {
private:
	std::vector<char> restricted_symbols {'!','$','+'};
public:
	bool is_valid(std::string password) {
		return std::all_of(password.begin(), password.end(), [this] (char character) {
			return std::none_of(restricted_symbols.begin(), restricted_symbols.end(), [character] (char symbol) {
				return character == symbol;});});
	}
};
void test7()
{
	std::cout << "Test7" << std::endl;
	
	// Password_Validator1 --------------------------------------------------
	std::string password {"holywood1$"};
	Password_Validator1 pv1;
	
	// Test whether password is valid
	if (pv1.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	// Test whether new password is valid
	password = "hollywood1";
	if (pv1.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
        
	std::cout << "\n";

	// Password_Validator2 --------------------------------------------------
	password = "C++Rocks!";
	Password_Validator2 pv2;
	
	// Test whether password is valid
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	// Test whether new password is valid
	password = "CPlusPlusRocks!";
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	// Test whether new password is valid
	password = "CPlusPlusRocks";
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
}
int main()
{   
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    return 0;
}
