#include "Hand.h"

void Hand::clear() {
    cards.clear();
}

void Hand::addCard(Card card) {
    cards.emplace_back(card);
}

int Hand::getValue() const {
    int handValue = 0;
    int aceCount = 0;

    for (auto card : cards) {
        if (card.getValue() == Card::Value::Ace) {
            aceCount++;
        }
        handValue += getCardValue(card);
    }

    while (aceCount > 0) {
        if (handValue > 21) {
            handValue -= 10;
        }
        aceCount--;
    }

    return handValue;
}

const std::vector<Card>& Hand::getCards() const {
    return cards;
}

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
