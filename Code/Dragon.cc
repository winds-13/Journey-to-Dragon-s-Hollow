#include "Player.h"

Dragon::Dragon(){         //ctor
    name = 'D';
    row = 4;
    column = 25;
    direction=-1;
    type = 'D';         //type is dragon
}

Dragon::~Dragon(){};

int Dragon::updateRow(){    //update movement
    if(row == 2){
        direction = -1;     //move down
    }else if(row == 4){
        direction = 1;      //move up
    }

    if(direction == -1){
        row += 1;            //move down
    }else{
        row -= 1;           //move up
    }
    return row;
}

int Dragon::updateCol(){        //update movement
    return column;
}


void Dragon::collide(Player* p){        //nothing will happen
    return;
}


bool Dragon::isHealthy(){               //a dragon is always healthy
    return true;
}


