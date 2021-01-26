#include "Player.h"
#include "Path.h"


Player::Player(){
    wasted = false;     // not dead
}

Player::~Player(){

};

char Player::getName(){      //name getter
    return name;
}

int Player::getStrength(){
    return strength;
}

int Player::getRow(){         //position row getter
    return row;
}

int Player::getColumn(){      //position column getter
    return column;
}

int Player::getHealth(){      //health getter
    return health;
}
        
bool Player::isWasted(){      //wasted???? (dead?)
    return wasted;
}

char Player::getType(){         //return type
    return type;
}



void Hero::injured(int d){        //innovative feature use only
    health -= d;
    if(d<0){                        //innovative feature, angel add health
        Hero* temp;
        int max = temp->MAX_HEALTH;
        if (health>=max){
            health = max;
        }
        cout<<name<<" got cured by an angel"<<endl;
    }

    if (health <= 0){
        health = 0;
        wasted = true;
    }
    cout<<name<<" health: "<<health<<endl;
}

void Player::setPosition(int r, int c){        //set position (row, column)
    if(r<1||r>5||c<1||c>25){
        if(r<1){
            r = 1;
        }
        if(c>25){
            c=25;
        }
        if(c<1){
            c=1;
        }
        if(r>5){
            r=5;
        }
        row = r;
        column = c;
    }else{
        row = r;
        column = c;
    }
}

void Player::setHealth(int e){      //set health, boundary checking

    health = (e>0) ? 0 : e;

    if(health <= 0){
        wasted = true;
    }
}