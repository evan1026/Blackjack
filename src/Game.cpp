#include "Game.h"

#define MAX_SCORE 21
#define DEALER_MIN_SCORE 17

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

void Game::hit() {
    if (isPlaying()) {
        playerHand.addCard(deck.draw());

        if (getPlayerScore() > MAX_SCORE) {
            state = State::LOSE;
            busted = true;
        }
    }
}

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
