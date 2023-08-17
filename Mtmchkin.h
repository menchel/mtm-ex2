//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include "Player.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);

    //copy constructor (was told in piazza that it is needed)
    Mtmchkin(const Mtmchkin& other);

    //assignment operator (was told in piazza that it is needed)
    Mtmchkin& operator=(const Mtmchkin& other);
    //destructor
    ~Mtmchkin();
    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    //TODO: complete the Mtmchkin class.

private:
    //TODO: complete the Mtmchkin class.    
    int m_nextCardIndex;
    int m_numOfCards;
    Player m_player;
    GameStatus m_status;
    Card *m_cardsArray;
    static const int MAX_PLAYER_LEVEL=10;

    void updateStatus();
    void updateNextCardIndex();
};


#endif //EX2_GAME_H
