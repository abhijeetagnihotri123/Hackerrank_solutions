#include <iostream>
#include <string>

using namespace std;

class Player
{
    private:
        string name;
        int health;
        int xp;
    public:
        void set_name(string name)
        {
            this->name = name;
        }
        void set_health(int health)
        {
            this->health = health;
        }
        void set_xp(int xp)
        {
            this->health = xp;
        }
        string get_name()
        {
            return this->name;
        }
        int get_health()
        {
            return this->health;
        }
        int get_xp()
        {
            return this->xp;
        }
        void display(void);
        Player();
        // {   
        //     cout<<"Default Constructor"<<endl;
        //     this->name = "Untitled";
        //     this->health = 100;
        //     this->xp = 5;
        // }
        Player(string);
        // {
        //     cout<<"Parameterized Constructor 1 parameter"<<endl;
        //     this->name = name;
        //     this->health = 100;
        //     this->xp = 5;
        // }
        Player(string,int,int);
        // {
        //     cout<<"Parameterized Constructor"<<endl;
        //     this->name = name;
        //     this->health = health;
        //     this->xp = xp;
        // }
        Player(const Player&);
        ~Player();
        // {
        //     cout<<"Destructing Object"<<endl;
        // }
};
void Player::display(void)
{
    cout<<get_name()<<" "<<get_health()<<" "<<get_xp()<<endl;
}
Player::Player()
    :name{"Untiled"},health{0},xp{0}
{
    cout<<"Default Constructor"<<endl;
}
Player::Player(string name,int health,int xp)
    :name{name},health{health},xp{xp}
{
    cout<<"Parameterized Constructor all arguments"<<endl;
}
Player::Player(string name)
    :name{name},health{100},xp{5}
{
    cout<<"Parameterized constructor 1 argument"<<endl;
}
Player::Player(const Player &source)
    : name(source.name), health(source.health), xp{source.xp} {
        cout << "Copy constructor - made copy of: " << source.name << endl; 
}
Player::~Player()
{
    cout<<"Destructing Object"<<endl;
}
int main(int argc,char *argv[])
{   
    Player p;
    p.display();
    Player p1("Leo_tolstoy",121,11);
    p1.display();
    Player p2("Pakhom");
    p2.display();
    Player p3{p2};
    p3.display();
    fun(p);
    return 0;
}
