#include "Game.h"

#define MAX_SCORE 21
#define DEALER_MIN_SCORE 17

Game::Game() :
    playerHand(), dealerHand(), deck(), state(State::NOT_STARTED),
    busted(false)
{}

/* Clears the player and dealer hands, shuffles the deck, deals cards,
 * and sets up the current game state. If the dealer got blackjack,
 * the state is either set to TIE or LOSE based on whether the player
 * also got blackjack. Otherwise, the state is set to PLAYING.
 */
void Game::start() {
    state = State::PLAYING;

    playerHand.clear();
    dealerHand.clear();

    deck.shuffle();

    playerHand.addCard(deck.draw());
    playerHand.addCard(deck.draw());

    dealerHand.addCard(deck.draw());
    dealerHand.addCard(deck.draw());

    if (getDealerScore() == MAX_SCORE) {
        if (getPlayerScore() == MAX_SCORE) {
            state = State::TIE;
        } else {
            state = State::LOSE;
        }
    }
}

/* Deals the player a card. If the player goes over the max
 * score, sets the state to LOSE and sets the busted flag.
 */
void Game::hit() {
    if (isPlaying()) {
        playerHand.addCard(deck.draw());

        if (getPlayerScore() > MAX_SCORE) {
            state = State::LOSE;
            busted = true;
        }
    }
}

/* Ends the game by drawing the dealer up to his minimum score and
 * then calculating the game's final state. If the dealer busts or
 * the player has a greater score, the state is set to WIN. If the
 * player and dealer have the same score, the state is set to TIE.
 * Otherwise, the dealer has a greater score, so the state is set
 * to LOSE.
 */
void Game::stay() {
    if (isPlaying()) {
        while (getDealerScore() < DEALER_MIN_SCORE) {
            dealerHand.addCard(deck.draw());
        }

        int dealerScore = getDealerScore();
        int playerScore = getPlayerScore();

        if (dealerScore > MAX_SCORE || playerScore > dealerScore) {
            state = State::WIN;
        } else if (playerScore == dealerScore) {
            state = State::TIE;
        } else {
            state = State::LOSE;
        }
    }
}

Game::State Game::getState() const {
    return state;
}

bool Game::isStarted() const {
    return getState() != State::NOT_STARTED;
}

bool Game::isPlaying() const {
    return getState() == State::PLAYING;
}

bool Game::isBusted() const {
    return busted;
}

bool Game::isWin() const {
    return getState() == State::WIN;
}

bool Game::isLose() const {
    return getState() == State::LOSE;
}

bool Game::isTie() const {
    return getState() == State::TIE;
}

const Hand& Game::getPlayerHand() const {
    return playerHand;
}

const Hand& Game::getDealerHand() const {
    return dealerHand;
}

int Game::getPlayerScore() const {
    return playerHand.getValue();
}

int Game::getDealerScore() const {
    return dealerHand.getValue();
}
