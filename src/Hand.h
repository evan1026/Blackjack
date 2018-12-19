#pragma once

#include "Card.h"

/** \class Hand
  * \brief This class represents a player's hand
  *
  * Internally there is a list of cards which can be populated
  * by calling addCard(). The list of cards can be accessed via
  * getCards() and calling getValue() will calculate the value
  * of the hand.
  */
class Hand {
    /// The list of cards in this hand
    std::vector<Card> cards;

    public:
        /// Default constructor
        Hand() : cards() {}

        /// Clears all of the cards out of the hand
        void clear();

        /** \brief Adds a card to the hand
          * \param  card  The card to add to the hand
          */
        void addCard(Card card);

        /** \brief Calculates the value of the hand and returns it
          * \return  The value of the hand according to blackjack rules
          */
        int getValue() const;

        /** \brief Return the list of cards in this hand
          * \return  This hand's list of cards
          */
        const std::vector<Card>& getCards() const;

    private:
        /** \brief Helper function that translates cards to integer values
          * \param   card  The card to calculate the value for
          * \return  The value of the card
          */
        int getCardValue(const Card& card) const;
};
