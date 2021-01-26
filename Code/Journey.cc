#include <iostream>
using namespace std;
#include <iomanip>
#include "Journey.h"
#include <iterator>
#include <list>


int random(int, int);

Journey::Journey(){     //ctor
    over = false;
    Timmy* t = new Timmy();
    Harold* h = new Harold();
    Dragon* d = new Dragon();
    l.push_back(t);
    l.push_back(h);
    l.push_front(d);            //by this, the heroes will always be at the last two position
}

Journey::~Journey(){
    list<Player*>::iterator rem;
    for(rem=l.begin();rem!=l.end();){
        Player* toBeDelete = *rem;
        rem = l.erase(rem);
        delete toBeDelete;   
    }
}

// the structure of the list will always be: 
    // [the dragon, fighter1, fighter2, fighter3, ..., angel1, angel2, ..., Timmy, Harold]
void Journey::update(){             //the main function that get the program working
    //find two heroes for future use
    list<Player*>::iterator mark;
    mark = l.end();
    mark--;
    Player* Ha = *mark;
    mark--;
    Player* Tim = *mark;

    list<Player*>::iterator angel;      //innnovative feature, to make sure all angels are together in list
    angel=mark;

    //create and add angels
    int chance = random(1,5);
    if(chance == 1){
        Angel* a = new Angel();
        l.insert(mark, a);
        
    }

    for(angel=l.begin();angel!=mark;angel++){       //move pointer for angels, make sure all fighters are added before position of angels
        if ((*angel)->getType()=='A'){
            break;
        }
    }
 
    //create and add fighters
    chance = random(1,5);
    if(chance != 1 && chance !=2){  //the 60% create a fighter
        //decide create which fighter
        chance = random(1,3);
        if(chance == 1){
            Dorc* d = new Dorc();
            l.insert(angel, d);         //all fighters are being added before positions of angels in the list
        }else if(chance == 2){
            Borc* b = new Borc();
            l.insert(angel, b);
        }else{
            Porc* p = new Porc();
            l.insert(angel, p);
        }
        
    }

    
    int oldRow, newRow, oldCol, newCol;
    
    list<Player*>::iterator itr;

    //first step, move all player, update their positions.
    for (itr=l.begin(); itr!= l.end(); itr++){
        
        if((*itr)->isWasted()){         //if a hero is wasted, skip it
            continue;
        }
        oldRow = (*itr)->getRow();
        oldCol = (*itr)->getColumn();
        //move it
        newRow = (*itr)->updateRow();
        newCol = (*itr)->updateCol();
        p.move((*itr)->getName(), oldRow, oldCol, newRow, newCol);

    }


    //second step, innovative feature, check collision for angel
    list<Player*>::iterator a;
    list<Player*>::iterator tempF;

    //determine angle's live and death
    for (a = angel; a!=mark; a++){    //all angels
        //check if an angel will die this round
        for (tempF=l.begin(); tempF!=angel; tempF++){    //all fighters
            //if an angel meets a fighter alone
            if(samePosition(*a, *tempF) &&(!samePosition(*a, Tim) && !samePosition(*a, Ha))){       //and no heroes' there to protect her
                (*a)->collide(*tempF);   //it dies in the collide function
                p.angelWasted(*a);
            }
        }
        //check if there is any hero nearby ,recover health
        if(inAngelRange(*a, Tim)&&inAngelRange(*a, Ha)){    //if both hero in angel range
            if(!(Tim->isHealthy()&&Ha->isHealthy())){        //if not both heroes are healthy
                Angel *temp = dynamic_cast<Angel*>(*a);
                if(!Ha->isHealthy()){                       //Tim is healthy, recover 2 point to Harold
                    Hero* newH = dynamic_cast<Hero*>(Ha);
                    newH->injured(-temp->getCure());
                }else if(!Tim->isHealthy()){
                    Hero* newT = dynamic_cast<Hero*>(Tim);

                    newT->injured(-temp->getCure());         //Tim is not healthy, recover 2 point to Timmy
                }
            }
        }else if(inAngelRange(*a, Tim)){                //if only Tim is in range
            Angel *temp = dynamic_cast<Angel*>(*a);
            Hero* newT = dynamic_cast<Hero*>(Tim);
            newT->injured(-temp->getCure());         //Tim recover 2 point
        }else if (inAngelRange(*a, Ha)){                                          // only harold is in range
            Angel *temp = dynamic_cast<Angel*>(*a);
            Hero* newH = dynamic_cast<Hero*>(Ha);
            newH->injured(-temp->getCure());         //Harold recover 2 point
        }

    }

    //third step, check collision for heroes and fighters
    for (itr=l.begin(); itr!= angel; itr++){ //'mark' is the index before two heroes
        if(samePosition(Ha, Tim)){      // if tim and harold are together
            if (samePosition(Tim, *itr)){      
                if ((*itr)->getType() == 'D'){  // if this fighter is a dragon
                    Tim->collide(*itr);         // they are both wasted in collide function
                    Ha->collide(*itr); 
                    break;       
                }else{                          //innovative feature, two hero fight one fighter, each take half damage
                    collideTogether(Tim,Ha,*itr);
                }
            }else{      //no collision with a fighter                         
                continue;
            }
            
        }else{   //two heroes not together
            //check collision for tim
            if (samePosition(Tim, *itr)){     
                Tim->collide(*itr);
                (*itr)->collide(Tim);
            }

            if(samePosition(Ha, *itr)){
                Ha->collide(*itr);
                (*itr)->collide(Ha);
            }

        }
    }

    //remove wasted fighters and angels from the list
        list<Player*>::iterator rem;
        for(rem=l.begin();rem!=mark;){
            if((*rem)->isWasted()){
                Player* toBeDelete = *rem;
                rem = l.erase(rem);
                delete toBeDelete;
            }else{
                rem++;
            }
        }
       


    //after collision, check if both hero are still alive;
    
    if(Tim->isWasted()){
        p.heroWasted(Tim);          //mark grave
    }
    if(Ha->isWasted()){
        p.heroWasted(Ha);            //mark grave
    }
    if(Tim->isWasted() && Ha->isWasted()){
        cout<<"Too bad, both heroes are wasted."<<endl; 
            p.print();
            over=true;
            return;
    }

    //check winner
    // if both players are alive && reach destination && they are together
    if(!Ha->isWasted() && !Tim->isWasted() && p.reachEnd(Ha) && p.reachEnd(Tim)){
        cout<<"Both of them made it!"<<endl;
        over = true;
    }else if(!Tim->isWasted() && p.reachEnd(Tim)){     //if tim is alive && reach destination
        cout<<"Tim made it!"<<endl;
        over = true;
        

    }else if(!Ha->isWasted() && p.reachEnd(Ha)){
        cout<<"Harold made it!"<<endl;
        over = true;
    }


    //print map
    p.print();
    cout<<endl<<endl;
   
  

      
        
    

    
    
   
   
    

    

    
}

void Journey::collideTogether(Player* t, Player* h, Player* f){     //if two heroes fight one fighter, each hero take half damage, timmy rounds up
    if(f->getType()=='d'){  // if two heroes meet a dragon together, send them to the collide function where they will die
        cout<<"two heroes meet dragon"<<endl;
        t->collide(f);
        h->collide(h);
        return;
    }
    //if it's not the dragon they meet, things will be easier for them, Timmy will take the rounded up damage
    cout<<"Two heroes fighting a "<<f->getName()<<" together."<<endl;
    int damageT, damageH;
    damageH = f->getStrength()/2;
    damageT = f->getStrength() - damageH;
    Hero* newT = dynamic_cast<Hero*>(t);
    Hero* newH = dynamic_cast<Hero*>(h);
    newT->injured(damageT);
    newH->injured(damageH);

}

bool Journey::isOver(){     //if good game
    return over;
}


bool Journey::samePosition(Player* p1, Player* p2){                         //check if two players are at the same position
    if(p1->isWasted()||p2->isWasted()){
        return false;
    }
    if((p1->getRow()==p2->getRow())&&(p1->getColumn()==p2->getColumn())){
        return true;
    }
    return false;
}


bool Journey::inAngelRange(Player* angel, Player* hero){            //check if a hero is in an angel's recovery

    int rowU = angel->getRow()+1;
    int rowD = angel->getRow()-1;
    int colL = angel->getColumn()-1;
    int colR = angel->getColumn()+1;


    int cRow = hero->getRow();
    int cCol = hero->getColumn();

    if((cRow>=rowD && cRow<=rowU)&&(cCol>=colL&&cCol<=colR)){
        return true;
    }


    return false;

}
