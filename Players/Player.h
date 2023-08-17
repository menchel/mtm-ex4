#ifndef PLAYER_H
#define PLAYER_H
#include "../HealthPoints.h"
#include <ostream>
#include <string>
class Player
{
    public:

        //constractor of the player
        //@name- the name of the player
        //@maxHP- maximum health points for the player
        //@force- the force of the player
        //returns a new instance of the player
        Player(const std::string& name,const int force=DEFAULT_FORCE);

        //destructor
        virtual ~Player()=default;

        //copy constructor
        Player(const Player& other)=default;

        //= operator
        Player& operator=(const Player& other)=default;

        //lift the players level by 1
        //if level is not less than 10, the function does nothing
        void levelUp();

        //getter for the player level
        int getLevel() const;

        //buff the player points by the parameter given
        void buff(const int forcePoints);

        //heals the player by the amount of points given
        //cannot heal to a HP of more than maxHP
        //if argument is smaller than 0 it will do nothing
        virtual void heal(const int healPoints);

        //damages the player by the amount of points given
        //cannot remove to a smaller HP than 0
        //if argument is smaller than 0 it will do nothing
        void damage(const int damgaePoints);

        //Returns if the player's HP reached 0
        bool isKnockedOut() const;

        //adds the coins to the player
        //override by ninja
        virtual void addCoins(const int coins);

        //returns if the player can pay the given price
        //if he can, he pays
        //else he does nothing
        bool pay(const int price);

        //downgrades the player force by 1
        //if player force is already 0, will do nothing
        void forceDownGrade();

        //returns the attack streangth of the player
        virtual int getAttackStrength()const;

        //returns the amount of coins that the player has
        int getCoins() const;
        
        //returns the player name
        std::string getName() const;
        
        //printing operator
        friend std::ostream& operator<<(std::ostream& os,const Player& playerObject);

    protected:
        static const int DEFAULT_FORCE=5;
        int m_force;
        int m_level;
        HealthPoints m_healthPoints;
        const std::string m_name;
        int m_coins;
    private:
        static const int START_LEVEL=1;
        static const int MAX_LEVEL=10;
        static const int STARTY_COINS=10;

        //returns an object to print the player's info
        //must be overrided
        virtual void printInfo(std::ostream& os) const=0;

};
#endif
