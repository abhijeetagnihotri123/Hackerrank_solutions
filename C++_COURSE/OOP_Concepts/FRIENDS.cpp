#include <iostream>
#include <string>

using namespace std;

class Player
{
    friend void display(Player &);
    private:
        string name;
        int health;
        int xp;
    public:
        string get_name(){return name;}
        int get_health(){return health;}
        int get_xp(){return xp;}
        Player(string,int,int);
        Player(void);
        ~Player(void);
};
Player::Player(string name,int health,int xp)
    :name{name},health{health},xp{xp}
{
    cout<<"All args constructor called"<<endl;
}
Player::Player()
    :Player{"Untitled",100,5}
{
    cout<<"No args constructor called"<<endl;
}
Player::~Player()
{
    cout<<"Destroying player"<<endl;
}
void display(Player &p)
{
    cout<<p.name<<" "<<p.health<<" "<<p.xp<<endl;
}
int main()
{   
    Player p("KATROX",121,11);
    display(p);
    return 0;   
}