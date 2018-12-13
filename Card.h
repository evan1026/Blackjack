#pragma once

#include <string>
#include <ostream>
#include <map>
#include <vector>

class Card {
    public:
        enum class Suit {
            Heart,
            Diamond,
            Spade,
            Club
        };
        enum class Value {
            Ace,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight,
            Nine,
            Ten,
            Jack,
            Queen,
            King
        };

    private:
        Suit suit;
        Value value;

        const static std::map<Suit, std::string> suitNames;
        const static std::map<Value, std::string> valueNames;
        const static std::vector<Suit> suits;
        const static std::vector<Value> values;

    public:

        Card(Suit suit_, Value value_) : suit(suit_), value(value_) {}

        Suit getSuit() const {
            return suit;
        }

        Value getValue() const {
            return value;
        }

        static const std::vector<Suit>& getSuits() {
            return suits;
        }

        static const std::vector<Value>& getValues() {
            return values;
        }

        friend std::ostream& operator<<(std::ostream& os, const Value& value) {
            os << valueNames.at(value);
            return os;
        }

        friend std::ostream& operator<<(std::ostream& os, const Suit& value) {
            os << suitNames.at(value);
            return os;
        }

        friend std::ostream& operator<<(std::ostream& os, const Card& card) {
            os << card.getValue() << " of " << card.getSuit();
            return os;
        }
};
