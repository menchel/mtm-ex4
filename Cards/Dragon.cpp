#include "Dragon.h"
#include "BattleCard.h"
#include "../utilities.h"
Dragon::Dragon():BattleCard("Dragon",25,1000,10)//need to change to the consts
{

}

void Dragon::printInfo(std::ostream& os)const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot,true);
    printEndOfCardDetails(os);
}


void Dragon::activateLoss(Player& player) const
{
    while(!player.isKnockedOut())
    {
        player.damage(DEFAULT_DAMAGE);
    }
}

