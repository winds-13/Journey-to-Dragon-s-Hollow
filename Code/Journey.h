#ifndef JOURNEY_H
#define JOURNEY_H
#include "Path.h"
#include "Player.h"
#include <list>

class Journey{
    public:
        Journey();      //ctor
        ~Journey();     //dtor
        bool isOver();      //check if it's good game
        void update();      //update all players' location, check collision, check if it's wasted
        bool samePosition(Player*, Player*);        //just a helper function to check if two players are at the same position
        void collideTogether(Player*, Player*, Player*);    //innovative feature, when both heroes fighting one fighter
        bool inAngelRange(Player*, Player*);        //check if hero(2) is in an angel(1)'s range
    private:
        Path<char> p;   //the display
        bool over;      //good game
        list<Player*> l;    //the list that have all players
        
};




#endif