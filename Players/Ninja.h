#ifndef NINJA_H
#define NINJA_H
#include "Player.h"
#include <ostream>
class Ninja: public Player
{
     //prints the info of the ninja to os
     //overrides from Player
     void printInfo(std::ostream& os) const override;

     static const int MONEY_FACTOR=2;
public:

     //constructor
     Ninja(const std::string& name,const int force=DEFAULT_FORCE);

     //destructor
     virtual ~Ninja()=default;

     //copy constructor
    Ninja(const Ninja& other)=default;

    //= operator
    Ninja& operator=(const Ninja& other)=default;

     //adds the coins to the player
     //overrides from player
     void addCoins(const int coins) override;

};
#endif // NINJA_H
