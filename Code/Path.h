#include <iostream>
using namespace std;
#include <cstdlib>
#include "Player.h"
template <class T>


class Path{ 
    public:
        Path();     //ctor
        ~Path();    //dtor
        void print() const;    //display
        void move(char, int, int, int, int);     // move a player
        void heroWasted(Player*);         // a hero died
        void fighterWasted(Player*);      // a fighter wasted
        bool reachEnd(Player *);           //check if a hero reaches destination
        void angelWasted(Player*);          //an angel is wasted
    private:
        T** arr;
        
};

 
template <class T>
Path<T>::Path(){                       //ctor

    arr = new T*[7];                //initialize the 2D array
    for (int i=0; i<7; i++){
        arr[i] = new T[28];
    }

    for(int i=0; i<7; i++){        //set all to null
        for (int j=0; j<28; j++){
            arr[i][j] = ' ';
        }
    }
}

template <class T>  
Path<T>::~Path(){               //dtor
    for (int i=0; i<7; i++){
        delete arr[i];
    }
    delete arr;
}

template <class T>
void Path<T>::move(char name, int oldRow, int oldCol, int newRow, int newCol){      //move a player
    // we want to make sure the '+' is always there
    if(arr[oldRow][oldCol] == '+'){
        ;
    }else{
        if(arr[oldRow][oldCol]==name){
            arr[oldRow][oldCol] = ' ';
        }
    }
    
    if(arr[newRow][newCol] == '+'){
        ;
    }else{
        arr[newRow][newCol] = name;
    }
} 

template <class T>
bool Path<T>::reachEnd(Player* p){       //check if a hero reaches destination
    if(p->getColumn()==25 && p->getRow()>=2 && p->getRow()<=4){
        return true;
    }
    return false;
}


template <class T>
void Path<T>::print() const{

    for (int i=0; i<7; i++){
        for(int j=0; j<28; j++){
            if (j==0||j==26){
                if(j==26 && i>=2 && i<=4){
                    cout<<'='<<' ';
                }else{
                    cout<<'|'<<' ';
                }
            }else if ((i==0||i==6)&&j!=27){
                cout<<'-'<<' ';
            }else if (j==27&&i==3){
                cout<<'*'<<' ';
            }else{
                if(arr[i][j]!=' '){
                    cout<<arr[i][j]<<' ';
                }else{
                    cout<<' '<<' ';
                }
               
            }
            
        }
        cout<<endl;
    }
}

template <class T>
void Path<T>::heroWasted(Player* h){     //if a hero is wasted, mark +
    if(arr[h->getRow()][h->getColumn()] == '+'){
        return;
    }
    cout<<"marked "<<h->getName()<<"s' grave."<<endl;
    arr[h->getRow()][h->getColumn()] = '+';
}

template <class T>
void Path<T>::fighterWasted(Player* f){      //if a fighter is wasted, simply remove it
    cout<<"A fighter died, removing from game."<<endl;
    arr[f->getRow()][f->getColumn()] = ' ';
}

template <class T>
void Path<T>::angelWasted(Player* a){      //if a angel is wasted, simply remove it
    cout<<"An angel died, removed from game."<<endl;
    arr[a->getRow()][a->getColumn()] = ' ';
}







