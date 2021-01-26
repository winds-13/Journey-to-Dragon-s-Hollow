#include "Player.h"
#include "Path.h"

int random(int, int);

Hero::Hero(){
    health = MAX_HEALTH; // set health
    armour = 15;
    row = random(1,5);    //position y at start, random between 1 and 5
    column = 1;         //position x start at 1
    type = 'H';         //type is hero

}

Hero::~Hero(){};



void Hero::collide(Player* d){  //heroes only collides with non-heroes
    if (d->getName() == 'D'){
        health = 0;
        wasted = true;
        cout<<"Heroes never die until meet a dragon."<<endl;
        cout<<name<<" health: "<<health<<endl;
        return;
    }
    health = health - d->getStrength()+armour;
    if (health <= 0){
        health = 0;
        wasted = true;
    }
    cout<<"There was a fight between "<<name<<" and "<<d->getName()<<endl;
    cout<<name<<" health: "<<health<<endl;

   
}




int Hero::updateRow(){           //update position
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

bool Hero::isHealthy(){             //if is max health
    return (health = MAX_HEALTH);
}

int Hero::updateCol(){           //update position
    int r;
    if (wasted){
         return -1;
    }

    column+=1;

    setPosition(row,column);
    return column;

}


Timmy::Timmy(){
    name = 'T';     //set name
    strength = 3;   //set stength
    armour = 3;     //set armour

} 


Harold::Harold(){
    name = 'H';     //set name
    strength = 5;   //set stength
    armour = 1;     //set armour

} 