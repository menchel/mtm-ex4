#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"
#include <ostream>
class Warrior: public Player
{
     //prints the info of the ninja to os
     //overrides from Player
     void printInfo(std::ostream& os) const override;

     static const int FORCE_FACTOR=2;
public:

     //constructor
     Warrior(const std::string& name,const int force=DEFAULT_FORCE);

     //destructor
     virtual ~Warrior()=default;

     //copy constructor
    Warrior(const Warrior& other)=default;

    //= operator
    Warrior& operator=(const Warrior& other)=default;

    //returns the attack streangth of the player
    int getAttackStrength()const override;
};
#endif // WARRIOR_H

