#ifndef TREASURE_H
#define TREASURE_H
#include "Card.h"
class Treasure : public Card
{
    static const int COINS=10;
    public:

        //constructor
        Treasure();

        //destructor
        ~Treasure()=default;

        //apllies encounter with the card
        //overrides the method from Card class
        void applyEncounter(Player& player) const override;
};
#endif