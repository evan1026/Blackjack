#pragma once

#include "Hand.h"
#include "Deck.h"

class Game {

    enum class State {
        NOT_STARTED,
        PLAYING,
        WIN,
        TIE,
        LOSE
    };

    Hand playerHand;
    Hand dealerHand;
    Deck deck;
    State state;
    bool busted;

    public:
        Game() : playerHand(), dealerHand(), deck(), state(State::NOT_STARTED), busted(false) {}
        void start();
        void hit();
        void stay();

        State getState() const;
        bool isStarted() const;
        bool isPlaying() const;
        bool isBusted() const;
        bool isWin() const;
        bool isLose() const;
        bool isTie() const;

        const Hand& getPlayerHand() const;
        const Hand& getDealerHand() const;

        int getPlayerScore() const;
        int getDealerScore() const;
};
