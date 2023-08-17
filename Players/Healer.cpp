#include "Healer.h"
#include "Player.h"
#include "../utilities.h"
Healer::Healer(const std::string& name,const int force):Player(name,force)
{

}
void Healer::printInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Healer",m_level,m_force,m_healthPoints.getHealthPoints(),m_coins);
}

void Healer::heal(const int healPoints)
{
    Player::heal(HEAL_FACTOR*healPoints);
}

