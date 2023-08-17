#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <queue>
#include <stack>
#include "Players/Player.h"
#include "Cards/Card.h"
#include <memory>
using std::unique_ptr;
class Mtmchkin{

public:
    
   /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    Mtmchkin(const Mtmchkin& other)=delete;

    Mtmchkin& operator=(const Mtmchkin& other)=delete;

    ~Mtmchkin()=default;//most memory meangement is by shared_ptr and queue
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::queue<std::unique_ptr<Card>> m_deckOfCards;
    std::queue<std::shared_ptr<Player>> m_playerInGame;
    std::queue<std::shared_ptr<Player>> m_winners;
    std::stack<std::shared_ptr<Player>> m_losers;
    int m_rounds;
    static const int CARRAGE_RETURN=13;//for some reason it puts it in the start sometimes
    //checks if the card name is valid
    //throws DeckFileFormatError if fails
    void isValidCard(const std::string& name,int line);

    //sets the card deck
    //throws DeckFileNotFound and DeckFileFormatError
    void setCardDeck(std::ifstream& deckFile);

    //get the players number and classes
    void getPlayersFromUser();

    //prints the queues pf winners and in game
    void printQueue(std::queue<std::shared_ptr<Player>> queue ,int& ranking) const;

    //prints the stack of losers
    void printStack(std::stack<std::shared_ptr<Player>> stack,int& ranking) const;

    //return the number of players recieved from the user
    int getNumberOfPlayers() const;

    //sets the player
    //returns if he was actually set
    bool setPlayer(std::string& inputLine);

    //checks if the player name is valid
    bool checkName(std::string& name) const;

    //check if the player type is valid
    //if yes, than it creates him and put him in the queue
    bool checkPlayerType(std::string& name,std::string& type);

    std::vector<std::string> getWords(std::string& input) const;    

    static const int MAX_LEVEL=10;

    static const int NUM_OF_WORDS=2;
};
#endif /* MTMCHKIN_H_ */