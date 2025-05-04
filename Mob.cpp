//implementation file
//constructor prototype that argumenrts can be passed in example: Mob(string, int, int, int )
//this would be in the mob.h file, implementation would be like Mob::Mob(string n, int a, etc...)
//would be passed in the main file like Mob enemy("Bob", 15, 16, 78)
//we are not using this because I'd rather do all of them separatly because I want to have more stats.

#include "Mob.h"

Mob::Mob() {//this is a default constructor. two of these default contsructors will result in a did not compile.
    name = "John Doe";
    hp = 15;
    atk = 15;
    def = 15;


}
Mob::Mob(std::string n, int h, int a, int d) { //second overloaded constructor. non consrtuctor member functions can also be overloaded.
    name = n;
    hp = h;
    atk = a;
    def = d;
}

void Mob::setHP(int health) {
    hp = health;
}
int Mob::getHP() const{
    return hp;
}

void Mob::setATK(int attack) {
    atk = attack;
}
int Mob::getATK() const{
    return atk;
}

void Mob::setDEF(int defense) {
    def = defense;
}
int Mob::getDEF() const{
    return def;
}

void Mob::setName(std::string n) {
    name = n;
}
std::string Mob::getName() const{
    return name;
}

int Mob::getMobCount() const{
    return mobCount;
}

Mob::~Mob(){//can only be one destructor cause destructors dont take arguments
    delete unsafeGoldPouch;
}