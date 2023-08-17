#ifndef BATTLE_CARD_H
#define BATTLE_CARD_H
#include "Card.h"
class BattleCard : public Card
{
protected:
    const int m_force;
    const int m_loot;
    const int m_damage;

public:

    //constructor
    BattleCard(const std::string& name,const int force,const int loot,const int damage);

    //copy constructor
    BattleCard(const BattleCard& other)=delete;

    //assignment operator
    BattleCard& operator=(const BattleCard& other)=delete;

    //destructor
    virtual ~BattleCard()=default;

    //apllies encounter with the card
    //overrides the method from Card class
    void applyEncounter(Player& player) const override;

    //prints the info of the card to os
    virtual void printInfo(std::ostream& os)const override;

    //apply the result for a loss according to the card
    virtual void activateLoss(Player& player) const;
};
#endif // BATTLE_CARD_H
