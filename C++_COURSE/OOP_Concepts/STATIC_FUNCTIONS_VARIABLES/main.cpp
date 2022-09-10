#include "player.h"

using namespace std;

void display_active_players()
{
    cout<<"Number of Active players are "<<player::get_num_players()<<endl;
}

int main()  
{   
    display_active_players();
    player hero;
    display_active_players();
    
    {
        player frank{"Frank",121,11};
        display_active_players();
    }
    display_active_players();
    
    player *enemy = new player("Enemy", 100, 100);
    display_active_players();
    delete enemy;
    display_active_players();    

    return 0;
}