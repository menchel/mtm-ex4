#include "BattleCard.h"
#include "Card.h"
#include "../utilities.h"
BattleCard::BattleCard(const std::string& name,const int force,const int loot,const int damage): Card(name),m_force(force),m_loot(loot),m_damage(damage)
{

}
void BattleCard::printInfo(std::ostream& os) const
{
    printCardDetails(os,m_name);
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);
}
void BattleCard::applyEncounter(Player& player) const
{
    if(player.getAttackStrength()>=m_force)//win
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else
    {
        player.damage(m_damage);
        this->activateLoss(player);
        printLossBattle(player.getName(),m_name);
    }
}
void BattleCard::activateLoss(Player& player) const
{

}
