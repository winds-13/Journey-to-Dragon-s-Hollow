#include "Player.h"
#include "Path.h"

int random(int, int);

Fighter::Fighter(){
    health = MAX_HEALTH;    //set health
    row = random(1,5);    //position y at start, random between 1 and 5
    column = 25;         //position x start at 1
    wasted = false;     // not dead
    type = 'F';         //type is fighter
}

Fighter::~Fighter(){};

void Fighter::collide(Player* d){  //collision
    if(type == 'D'){        //others meet the dragon, others die, not the dragon
        return;
    }
    health -= d->getStrength();
    if (health <= 0){
        health = 0;
        wasted = true;
    }


   
}


int Fighter::updateRow(){      //update position
    int r;
    if (wasted){
         return -1;
    }
    r = random(0,1);
    if(r==0){
        row-=1;
    }else if(r==1){
        row+=1;
    }

    setPosition(row,column);
    return row;
}

int Fighter::updateCol(){           //update position
    int r;
    if (wasted){
         return -1;
    }

    column-=1;

    setPosition(row,column);
    return column;

}


bool Fighter::isHealthy(){
    return (health = MAX_HEALTH);
}

Dorc::Dorc(){
    name = 'd';      //set name
    strength = random(6,8);  //set strength;
}

Borc::Borc(){
    name = 'b';      //set name
    strength = random(8,11);  //set strength;
}

Porc::Porc(){
    name = 'p';      //set name
    strength = random(4,5);  //set strength;
}