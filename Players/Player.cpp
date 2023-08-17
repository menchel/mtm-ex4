#include "Player.h"
Player::Player(const std::string& name,const int force):m_force(force),m_level(START_LEVEL),m_healthPoints(),m_name(name),m_coins(STARTY_COINS)
{
    if(force<0)
    {
        m_force=DEFAULT_FORCE;
    }
}

void Player::levelUp()
{
    if(m_level<MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getCoins() const
{
     return m_coins;
}
void Player::forceDownGrade()
{
    if(m_force>0)
    {
        m_force--;
    }
}

std::string Player::getName() const
{
    return m_name;
}
int Player::getLevel() const
{
    return m_level;
}

void Player::buff(const int forcePoints)
{
    if (forcePoints > 0)
    {
        m_force += forcePoints;
    }
}

void Player::heal(const int healPoints)
{
    m_healthPoints+=healPoints;
}

void Player::damage(const int damgaePoints)
{
    if(damgaePoints>0)
    {
        m_healthPoints-=damgaePoints;
    }
}

bool Player::isKnockedOut() const
{
    return m_healthPoints<1;
}

void Player::addCoins(const int coins)
{
    if (coins > 0)
    {
        m_coins += coins;
    }
}

bool Player::pay(const int price)
{
    if(price>m_coins)
    {
        return false;
    }
    if (price <= 0)//according to FAQ published
    {
        return true;
    }
    m_coins-=price;
    return true;
}

int Player::getAttackStrength()const
{
    return m_force+m_level;
}

std::ostream& operator <<(std::ostream& os,const Player& playerObject)
{
    playerObject.printInfo(os);
    return os;
}
