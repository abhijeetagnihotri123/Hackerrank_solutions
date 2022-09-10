// This program is designed to crash to illustrate drawbacks of shallow copy

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
        Player();
        Player(string);
        Player(string,int,int);
        ~Player();
        string get_name(void){return this->name;}
        int get_health(void){return this->health;}
        int get_xp(void){return this->xp;}
        void display(void);
};
Player::Player(string name,int health,int xp)
    :name{name},health{health},xp{xp}
{
    cout<<"All args constructor called"<<endl;
}
Player::Player(string name)
    :Player{name,100,5}
{
    cout<<"One args constructor called"<<endl;
}
Player::Player()
    :Player{"Untitled",100,5}
{
    cout<<"No args constructor called"<<endl;
}
Player::~Player()
{
    cout<<"Destructor called"<<endl;
}
void Player::display(void)
{
    cout<<get_name()<<" "<<get_health()<<" "<<get_xp()<<endl;
}
int main()
{
    Player empty;
    Player frank("Frank");
    Player villian("Villian",121,11);
    empty.display();
    frank.display();
    villian.display();
    return 0;
}