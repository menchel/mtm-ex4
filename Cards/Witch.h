#ifndef WITCH_H
#define WITCH_H
#include "BattleCard.h"

class Witch: public BattleCard
{
    static const int DEFAULT_FORCE=11;
    static const int DEFAULT_LOOT=2;
    static const int DEFAULT_DAMAGE=10;
public:

    //constructor
    Witch();

    //destructor
    ~Witch()=default;
    
    //apply the result for a loss according to the card
    void activateLoss(Player& player) const override;
};
#endif // WITCH_H
