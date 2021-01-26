#include <iostream>
using namespace std;
#include "Journey.h"
#include <cstdlib> 
#include <unistd.h>



int random(int, int);



int main(){

   
    Journey j;    
    srand( (unsigned)time( NULL ) );

    while (!j.isOver()){
        sleep(1);
        j.update();
    }

}

