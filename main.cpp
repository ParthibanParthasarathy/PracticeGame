//no need for include iostream and include string because it is included in the Mob.h
#include "Mob.h"

class Tree
{
    private:
        static int objectCount;//static member variable
    public:
        Tree() //constrcutor
            {objectCount++;}
        static int getObjectCount() //accesor function
            {return objectCount;}
};

//definition of static member variable written outside class.
int Tree::objectCount = 0;
int Mob::mobCount = 0;

int main() {

    int tempInt;
    std::string hello = "Hello World!";    
    std::cout << hello << std::endl;



    Tree oak;
    Tree cyprus;
    Tree redwood;    

    


    Mob me;
    //std::cout<<me.getDEF(); testing if the contructor works. It does in fact work.

    
    //makes the enemy dynamic, allowing us to delete and make new ones without using up storage.
    Mob *enemyPtr = nullptr;

    enemyPtr = new Mob;

    enemyPtr->setHP(10);
    enemyPtr->setATK(10);
    enemyPtr->setDEF(10);
    enemyPtr->setName("bob");

    std::cout<<"What hp do you want?"<<std::endl;
    std::cin>>tempInt;
    me.setHP(tempInt);
    me.setATK(2);
    me.setDEF(10);
    me.setName("Me");


    
    //derefrencing enemyPtr to get the hp. remeber that the dot operator has precedence, so parenthesis were used. enemyPtr->getHP() is the other way to use it.
    while((*enemyPtr).getHP() > 0 && me.getHP()>0) {
        std::cout<<"FIGHT!"<<std::endl;
        enemyPtr->setHP(enemyPtr->getHP()-me.getATK());
        me.setHP(me.getHP() - enemyPtr->getATK());
        std::cout<<"Your HP is "<<me.getHP()<<std::endl;
        std::cout<<"Enemy HP is "<<enemyPtr->getHP()<<std::endl;

    }
    delete enemyPtr; //destroys the enemy after to free up space. can also use a destructor
    enemyPtr = nullptr;
    if(me.getHP()>0) {
        std::cout<<"You won!! Good job!!"<<std::endl;
    }
    else {
        std::cout<<"You lost!!!!! HAHAHAHAHAAHAHA!!!!!!"<<std::endl;
    }
    
    while(true) {
        std::string quit;
        std::cin>>quit;
        if (quit == "q") {
            exit(0);
        }

    }


    
    
}

