#include "Warrior.h"
#include "Player.h"
#include "../utilities.h"
Warrior::Warrior(const std::string& name,const int force):Player(name,force)
{

}
void Warrior::printInfo(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Warrior",m_level,m_force,m_healthPoints.getHealthPoints(),m_coins);
}

//returns the attack streangth of the player
int Warrior::getAttackStrength() const
{
    return m_force*FORCE_FACTOR+m_level;
}

