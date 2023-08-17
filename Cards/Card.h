#ifndef CARD_H
#define CARD_H
#include "../Players/Player.h"
class Card
{
public:

    Card(const std::string& name);
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const=0;
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    Card(const Card& other)=delete;

    //destructor
    virtual~Card() = default;

    //assignment operator
    Card& operator=(const Card& other) = delete;

    //returns the card's name
    std::string getName() const;

    //printing operator
    friend std::ostream& operator<<(std::ostream& os,const Card& cardObject);
protected:
    const std::string m_name;
private:

    //prints the card info to os
    virtual void printInfo(std::ostream& os) const;

};
#endif // CARD_H
