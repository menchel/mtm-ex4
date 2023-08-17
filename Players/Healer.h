#ifndef HEALER_H
#define HEALER_H
#include "Player.h"
#include <ostream>
class Healer: public Player
{
     //prints the info of the ninja to os
     //overrides from Player
     void printInfo(std::ostream& os) const override;

     static const int HEAL_FACTOR=2;
public:

     //constructor
     Healer(const std::string& name,const int force=DEFAULT_FORCE);

     //destructor
     ~Healer()=default;

     //copy constructor
    Healer(const Healer& other)=default;

    //= operator
    Healer& operator=(const Healer& other)=default;

    //heals the player by the amount of points given
    //cannot heal to a HP of more than maxHP
    //if argument is smaller than 0 it will do nothing
    void heal(const int healPoints) override;

};
#endif // HEALER_H
