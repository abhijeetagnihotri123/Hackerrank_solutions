#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <iostream>

class player
{
    private:
        static int num_players;
        std::string name;
        int health;
        int xp;
    public:
        std::string get_name(){return name;}
        int get_health(){return health;}
        int get_xp(){return xp;}
        player(std::string,int,int);
        player(const player&);
        player(void);
        ~player();
        static int get_num_players(void);
};
#endif