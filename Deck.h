#pragma once

#include <vector>

#include "Card.h"

class Deck {
    std::vector<Card> cards;
    int pos;

    public:
        Deck();
        void shuffle();
        Card draw();
};
