#pragma once

#include <vector>

#include "Card.h"

/** \class Deck
  * \brief Represents a deck of cards
  *
  * This class accurately reprents a deck of cards rather than just
  * generating random cards. It does this by populating a list of
  * cards with all 52 cards and then randomizing the order of the
  * list. Once the deck is shuffled, cards can be pulled one at a
  * time by calling draw().
  */
class Deck {
    /// The list of cards in this deck
    std::vector<Card> cards;
    /// The next card that will be returned when draw() is called
    int pos;

    public:
        /// Default constructor
        Deck();

        /** \brief Shuffles the deck
          *
          * Calls std::random_shuffle to randomize the order of the
          * deck. Make sure to call std::srand first to get random
          * results.
          */
        void shuffle();

        /** \brief Draws a card from the deck
          * \return  The next card in the deck
          *
          * Returns the next card from the deck. If we have reached the
          * end of the deck, this function shuffles the deck and then
          * returns the top card.
          */
        Card draw();
};
