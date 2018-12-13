#include <algorithm>

#include "Deck.h"

Deck::Deck() {
    auto suits = Card::getSuits();
    auto values = Card::getValues();

    cards.reserve(suits.size() * values.size());

    for (auto suit : suits) {
        for (auto value : values) {
            cards.emplace_back(Card(suit, value));
        }
    }

    pos = 0;
}

void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
    pos = 0;
}

Card Deck::draw() {
    if (pos >= cards.size()) {
        shuffle();
    }

    return cards.at(pos++);
}
