#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    private:
        int health;
        static int animalCount;
        
    public:
        void setHealth(int h) {health = h;}//inline function and an mutator function
        int getHealth() const {return health;}// Accessor fucntion 

        int value;
        Animal(int v): value(v) {}
};
#endif