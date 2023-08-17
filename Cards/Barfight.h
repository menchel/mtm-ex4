#ifndef BARFIGHT_H
#define BARFIGHT_H
#include "../Players/Player.h"

class Barfight:public Card
{
    static const int DAMAGE_FIGHT=10;
    public:

        //constructor
        Barfight();

        //destructor
        ~Barfight()=default;

        //apllies encounter with the card
        //overrides the method from Card class
        void applyEncounter(Player& player) const override;
};
#endif