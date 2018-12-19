#include "Hand.h"

void Hand::clear() {
    cards.clear();
}

void Hand::addCard(Card card) {
    cards.emplace_back(card);
}

/* Calculates the value of the hand according to blackjack rules.
 * Goes through each of the cards and adds up all of the values
 * of each card. During this loop, it also counts the number of
 * aces.
 *
 * After this is done, we need to make sure that we take care of
 * aces since they are 11 points unless that would put the hand
 * over 21, in which case they are 1 point. In order to take care
 * of them, we loop through each of the aces we counted before
 * and if the hand value is still greater than 21, then we drop
 * that ace's value down to 1.
 */
int Hand::getValue() const {
    int handValue = 0;
    int aceCount = 0;

    for (auto card : cards) {
        if (card.getValue() == Card::Value::Ace) {
            aceCount++;
        }
        handValue += getCardValue(card);
    }

    while (aceCount > 0 && handValue > 21) {
        handValue -= 10;
        aceCount--;
    }

    return handValue;
}

const std::vector<Card>& Hand::getCards() const {
    return cards;
}

/* Simple switch statement that maps cards to values. Could have
 * been an actual map but that was more work than it's really
 * worth.
 */
int Hand::getCardValue(const Card& card) const {
        switch (card.getValue()) {
            case Card::Value::Ace:
                return 11;
            case Card::Value::Two:
                return 2;
            case Card::Value::Three:
                return 3;
            case Card::Value::Four:
                return 4;
            case Card::Value::Five:
                return 5;
            case Card::Value::Six:
                return 6;
            case Card::Value::Seven:
                return 7;
            case Card::Value::Eight:
                return 8;
            case Card::Value::Nine:
                return 9;
            case Card::Value::Ten:
            case Card::Value::Jack:
            case Card::Value::Queen:
            case Card::Value::King:
                return 10;
        }
}
