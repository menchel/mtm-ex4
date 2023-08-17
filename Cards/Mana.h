#ifndef MANA_H
#define MANA_H
#include "../Players/Player.h"

class Mana:public Card
{
    static const int HEAL_POINTS=10;
    public:

        //constructor
        Mana();

        //destructor
        ~Mana()=default;

        //apllies encounter with the card
        //overrides the method from Card class
        void applyEncounter(Player& player) const override;
};
#endif