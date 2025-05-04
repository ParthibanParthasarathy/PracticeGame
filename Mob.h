#include <iostream>
#include <string>
#ifndef MOB_H
#define MOB_H

class Mob {
    private:
        static int mobCount; //static member variable
        std::string name;
        int hp;
        int atk;
        int def;
        int* unsafeGoldPouch; //excusivly meant to get destroyed. after getting destroyed, must use new int to avoid undefined behavior because it is a dangling pointer
        //want to make it into a roulewtte type bag where you can either loose or gain abunch of gold.
    public:
        Mob(); //contstructor
        Mob(std::string, int, int, int); //second overloaded constructor
        //these are the declarations for the class functions. The functions themeselves can also be in the public.
        void setHP(int);
        int getHP() const; 
        
        void setATK(int);
        int getATK() const;

        void setDEF(int);
        int getDEF() const;

        void setName(std::string);
        std::string getName() const;

        int getMobCount() const;

        ~Mob(); //destructor
};
//fucntions can be here if the contructor was made in the main.cpp, but because it is in its own
//implementation file, they need to get moved out to that file.


#endif