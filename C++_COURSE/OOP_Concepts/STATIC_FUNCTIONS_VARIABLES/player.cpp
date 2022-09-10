#include "player.h"

int player::num_players {0};

player::player(std::string name="Untitled",int health=100,int xp=5)
    :name{name},health{health},xp{xp}
{   
    std::cout<<"All args constructor called"<<std::endl;
    ++num_players;
}
player::player(const player &p)
    :player{p.name,p.health,p.xp}
{   
    std::cout<<"Copy constructor called"<<std::endl;
}
player::player()
    :player{"Untitled",100,5}
{   
    std::cout<<"One args constructor called"<<std::endl;
}
player::~player()
{   
    std::cout<<"Destroying player"<<std::endl;
    --num_players;
}
int player::get_num_players(void){return num_players;}