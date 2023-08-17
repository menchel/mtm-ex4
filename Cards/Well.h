#ifndef WELL_H
#define WELL_H
#include "../Players/Player.h"

class Well:public Card
{
    static const int WELL_DAMAGE=10;
    public:

        //constructor
        Well();

        //destructor
        ~Well()=default;

        //apllies encounter with the card
        //overrides the method from Card class
        void applyEncounter(Player& player) const override;
};
#endif