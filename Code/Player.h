#ifndef HERO_H
#define HERO_H
class Player{             //base class for all quest player
    public:
        Player();                         //ctor
        virtual ~Player();                        //dtor
        int getRow();                   //getter for position x
        int getColumn();                   //getter for position y
        virtual int updateRow()=0;         //virtual function update a position
        virtual int updateCol()=0;         //virtual function update a position
        char getName();                     //name getter
        int getStrength();                  //strength getter
        int getHealth();                    //health getter
        bool isWasted();                    //if it is wasted
        char getType();                     //get the name of its type
        virtual void collide(Player*)=0;      //collide
        virtual bool isHealthy()=0;           //innovative feature use, return if the player is max health

    protected:
        int row;                            //position x
        int column;                         //position y
        char name;                          //char shown on disply
        int health;                         //health
        bool wasted;                        //wasted or not (dead or not)
        void setHealth(int);                //set health
        void setPosition(int, int);         //set location (row, column), boundary checking
        int strength;                       //strength
        char type;                          //its' type
        


};


class Hero : public Player{         //base class for heroes
    public:
        Hero();
        ~Hero();
        const static int MAX_HEALTH = 15;   // max health for heroes
        virtual int updateRow();   //virtual update postion
        virtual int updateCol();   //virtual update postion
        virtual void collide(Player*);          //collide
        virtual bool isHealthy();       //innovative feature use only, return max health of a type
        void injured(int);            //innovative feature use only, when two player encouter one fighter, split the damage or angel give health
    protected:
        int armour;
};

class Fighter : public Player{         //base class for fighters
    public:
        Fighter();
        ~Fighter();
        const static int MAX_HEALTH = 5;   // max health for fighters
        virtual void collide(Player*);          //collide
        virtual int updateRow();   //virtual update postion
        virtual int updateCol();   //virtual update postion
        virtual bool isHealthy();       //innovative feature, return max health of a type
};

class Dragon : public Player{
    public:
        Dragon();
        ~Dragon();
        virtual int updateRow();
        virtual int updateCol();
        virtual void collide(Player*);          //collide
        virtual bool isHealthy();
        

    private:
        int direction;

};

class Angel : public Player{
    public:
        Angel();
        virtual int updateRow();                //update movement
        virtual int updateCol();                //update movement
        virtual void collide(Player*);          //collide
        virtual bool isHealthy();               
        int getCure();                  //getter for its ability to cure

    private:
        int direction;      //moving direction
        int radius;         //range of recovery
        int cure;           //number of health point can cure to a hero
};

class Timmy : public Hero{
    public:
        Timmy();                //ctor
        //virtual ~Timmy();       //virtual dtor
        
};

class Harold : public Hero{
    public:     
        Harold();               //ctor
        //virtual ~Harold();      //virtual dtor
        
};



class Dorc : public Fighter{        //dorc
    public:
        Dorc(); //ctor
        
};

class Borc : public Fighter{        //borc
    public:
        Borc();             //ctor
        
};

class Porc : public Fighter{        //porc
    public:
        Porc();                 //ctor
        
};

#endif