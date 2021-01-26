#include "Player.h"
#include "Path.h"


int random(int, int);

Angel::Angel(){
    name = 'a';             //set name
    row = random(1,5);    //position y at start, random between 1 and 5
    direction = -1;
    column = random(12,15);         //position x start at middle point
    type = 'A';         //type is Angel
    radius = 1;         //radius of recovering
    cure = 2;

}


void Angel::collide(Player* d){  //Angel collides
    if(d->getType() == 'F'|| d->getType()=='D'){       
        wasted = true;
    }

    if(d->getType() == 'H'){
        Hero* newD = dynamic_cast<Hero*>(d);
        newD->injured(-2);         //hero will get 2 health
        delete newD;
    }

   
}

int Angel::getCure(){           //get recovery value
    return cure;
}

int Angel::updateRow(){
    direction = random(0,1);

    if(direction == 0){
        row += 2;            //move down
    }else{
        row -= 2;           //move up
    }

    setPosition(row,column);
    return row;
}

int Angel::updateCol(){
    direction = random(0,1);
    if(direction == 0){
        column += 2;            //move down
    }else{
        column -= 2;           //move up
    }
    setPosition(row,column);

    return column;
}


bool Angel::isHealthy(){            //if an angel is alive, it is healthy
    return true;
}
