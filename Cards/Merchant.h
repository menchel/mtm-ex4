#ifndef MERCHANT_H
#define MERCHANT_H
#include "Card.h"
#include "../Players/Player.h"
#include <ostream>
class Merchant:public Card
{
    static const int HEALTH_PRICE=5;
    static const int FORCE_PRICE=10;
    static const int BUY_NOTHING=0;
    static const int BUY_HEALTH=1;
    static const int BUY_FORCE=2;

    //recieving the input from the user and trying to buy
    bool buyProduct(std::ostream& os,Player& player,int type) const;

    //checks if the product can be bought
    void tryToBuy(std::ostream& os,Player& player,int type,int cost) const;
    
    public:

        //constructor
        Merchant();

        //destructor
        ~Merchant()=default;

        //apllies encounter with the card
        //overrides the method from Card class
        void applyEncounter(Player& player) const override;
};
#endif