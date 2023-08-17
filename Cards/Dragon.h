#ifndef DRAGON_H
#define DRAGON_H
#include "BattleCard.h"
class Dragon: public BattleCard
{
    static const int DEFAULT_FORCE=25;
    static const int DEFAULT_LOOT=1000;
    static const int DEFAULT_DAMAGE=10;//doesnt really matter

    //prints the info of the ninja to os
    //overrides from Player
    void printInfo(std::ostream& os)const override;
public:

    //constructor
    Dragon();

    //destructor
    ~Dragon()=default;

    //apply the result for a loss according to the card
    void activateLoss(Player& player) const override;
};
#endif // WITCH_H

