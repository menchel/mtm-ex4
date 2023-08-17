#include "Ninja.h"
#include "Player.h"
#include "../utilities.h"
Ninja::Ninja(const std::string& name,const int force):Player(name,force)
{

}
void Ninja::printInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Ninja",m_level,m_force,m_healthPoints.getHealthPoints(),m_coins);
}

void Ninja::addCoins(const int coins)
{
    Player::addCoins(MONEY_FACTOR*coins);
}
