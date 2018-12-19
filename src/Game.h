/** \file Game.h
  * \brief Defines the Game class
  */

#pragma once

#include "Hand.h"
#include "Deck.h"

/** \class Game
  * \brief Contains state information to control the game as a whole
  *
  * After initializing a new game, the game can be started by calling
  * start(). After this, the player can hit by calling hit() or stay
  * by calling stay(). A call to isPlaying() or isBusted() should be
  * called after every hit to ensure that the player hasn't busted.
  * Once the user busts or stays, the dealer's turn is played and then
  * the game state is set to represent whether the player has won or lost.
  *
  * The game state can be accessed at any time by calling getState(),
  * or specific states can be queried using the following methods:
  *     - isStarted() - whether start() has been called yet
  *     - isPlaying() - whether the game is still being played
  *     - isBusted()  - whether the player has busted
  *     - isWin()     - whether the player has won
  *     - isLose()    - whether the player has lost
  *     - isTie()     - whether the player has tied
  */
class Game {

    public:
        /** \class State
          * \brief Enum representing the state of the game
          */
        enum class State {
            NOT_STARTED, ///< Enum state meaning the game has not been started yet
            PLAYING,     ///< Enum state meaning the game is being played (player still hitting)
            WIN,         ///< Enum state meaning the game is over, and the player won
            TIE,         ///< Enum state meaning the game is over, and the player tied the dealer
            LOSE         ///< Enum state meaning the game is over, and the player lost
        };

    private:
        Hand playerHand; ///< The player's hand
        Hand dealerHand; ///< The dealer's hand
        Deck deck;       ///< The deck we're drawing cards from
        State state;     ///< The current State of the game
        bool busted;     ///< Whether or not the player has busted

    public:
        /// Default constructor
        Game();

        // --------------------------------------------------------------------
        // Game mechanics
        // --------------------------------------------------------------------

        /** \brief   Starts the game
          *
          * Can be called multiple times to restart the game. Other
          * game mechanics will do nothing until the game is started.
          */
        void start();

        /** \brief   Performs a hit (gives the player another card)
          *
          * If the game wasn't started or it has ended, this function
          * does nothing.
          */
        void hit();

        /** \brief   Ends the game with whatever cards the user has
          *
          * This will cause the dealer to draw until he has reached the
          * minimum score, after which the game state will be set to
          * represent whether the user has won or lost.
          */
        void stay();

        // --------------------------------------------------------------------
        // Game state accessors
        // --------------------------------------------------------------------

        /// Returns the current game state
        State getState() const;

        /// Returns true if the game was started, false otherwise
        bool isStarted() const;

        /// Returns true if the game is currently being played (hasn't ended), false otherwise
        bool isPlaying() const;

        /// Returns true if the player busted, false otherwise
        bool isBusted() const;

        /// Returns true if the player won, false otherwise
        bool isWin() const;

        /// Returns true if the player lost, false otherwise
        bool isLose() const;

        /// Returns true if the game was a tie, false otherwise
        bool isTie() const;

        // --------------------------------------------------------------------
        // Hand information
        // --------------------------------------------------------------------

        /// Returns the value of the player's hand
        int getPlayerScore() const;

        /// Returns the value of the dealer's hand
        int getDealerScore() const;

        /// Returns the player's hand
        const Hand& getPlayerHand() const;

        /// Returns the dealer's hand
        const Hand& getDealerHand() const;

};
