#include <algorithm>

#include "Deck.h"

/* Generates the deck of cards by just iterating through all of the
 * suits and values and combines them to get all of the possible
 * cards.
 */
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

/* Shuffles the deck using std::random_shuffle. Make sure to call
 * std::srand first to generate actual random results.
 */
void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
    pos = 0;
}

/* Shuffles the deck if we have run out of cards and then returns
 * the next card.
 */
Card Deck::draw() {
    if (pos >= cards.size()) {
        shuffle();
    }

    return cards.at(pos++);
}
