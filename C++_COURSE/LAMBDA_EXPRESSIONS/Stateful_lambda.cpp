#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int global_x{1000};

void test1()
{   
    cout<<"Test1\n";
    int local_x{100};
    auto l = [local_x]()
    {
        cout<<"Global_x "<<global_x<<endl;
        cout<<"Local_x "<<local_x<<endl;
    };
    l();
}
void test2()
{   
    cout<<"Test2\n";
    int x = 120;
    auto l1 = [x]()mutable{
        x+=130;
        cout<<x<<endl;
    };
    l1();
    cout<<x<<endl;
    auto l2 = [&x]()mutable{
        x += 130;
    };
    l2();
    cout<<x<<endl;
}
void test3()
{
    cout<<"Test3\n";
    int x{100};
    int y{200};
    int z{300};
    auto l = [&]()mutable
    {
        x += 100;
		y += 100;
		cout << x << endl;
		cout << y << endl;
    };
    l();
    cout<<x<<" "<<y<<endl;
}
void test4()
{
	std::cout << "\n---Test4 --------------------------" << std::endl;
	
	int x {100};
	int y {200};
	int z {300};
	
	auto l = [&, x, z] () mutable {
		x += 100;
		y += 100;
		z += 100;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << z << std::endl;
	};
	l();
	
	std::cout << "\n";
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
}
class Person
{
    friend ostream &operator<<(ostream &,const Person &);
    private:
    string name;
    int age;
    public:
    Person()=default;
    Person(string name,int age):name{name},age{age}{}
    Person(const Person &p):name{p.name},age{p.age}{}
    ~Person()=default;
    string get_name() const { return name; }
    void set_name(std::string name) {this->name = name; };
    int get_age() const {return age; }
    void set_age(int age) {this->age = age; }   
    auto change_person1() {return [this] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
    auto change_person2() {return [=] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
	auto change_person3() {return [&] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

void test5()
{
    cout<<"Test5\n";
    Person person("Larry", 18);
	cout << person << endl;
	auto change_person1 = person.change_person1();
    change_person1("Moe",30);
	cout << person << endl;
    auto change_person2 = person.change_person2();
	change_person2("Curly", 25);
	std::cout << person << std::endl;
	
	// Default capture [&]
	auto change_person3 = person.change_person3();
	change_person3("Frank", 34);
	std::cout << person << std::endl;
}
class Lambda
{
    private:
        int y;
    public:
        Lambda(int y):y{y}{}
        void operator()(int x)
        {
            cout<<(x+y)<<endl;
        }
};
void test6()
{
    cout<<"Test6"<<endl;
    int y{100};
    Lambda l1(y);
    auto l2 = [y](int x){cout<<x+y<<endl;};
    l1(100);
    l2(100);
}
class People
{
    private:
        vector<Person>people;
        int max_people;
    public:
        People(int Max=10):max_people{Max}{}
        void add(std::string name, int age) {
        people.emplace_back(name, age);
        }
        void set_max_people(int max) {
            max_people = max;
        }
        int get_max_people() const {
            return max_people;
        }
        vector<Person> get_people(int max_age) {
        vector<Person> result;
        int count{0};
        copy_if(people.begin(), 
                           people.end(), 
                           back_inserter(result),
                            [this, &count, max_age](const Person &p){ return p.get_age() > max_age &&  ++count<=max_people;});
        return result;
    }
};
void test7() {
   	std::cout << "\n---Test10 --------------------------" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);
    
    auto result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
        
    friends.set_max_people(3);
    
    result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
        
    result = friends.get_people(50);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
}
int main()
{   
    test7();
    return 0;
}