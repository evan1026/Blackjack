#include "Card.h"

class Hand {
    std::vector<Card> cards;

    public:
        Hand() : cards() {}
        void clear();
        void addCard(Card card);
        int getValue() const;
        const std::vector<Card>& getCards() const;

    private:
        int getCardValue(const Card& card) const;
};
