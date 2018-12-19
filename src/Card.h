#pragma once

#include <string>
#include <ostream>
#include <map>
#include <vector>

/** \class Card
  * \brief Class representing a single card
  *
  * Just a basic class that has a value and a suit. This class
  * also contains enums for the values and the suits.
  */
class Card {
    public:
        /** \class Suit
          * \brief Enum for card suits
          */
        enum class Suit {
            Heart,      ///< Enum value for Hearts
            Diamond,    ///< Enum value for Diamonds
            Spade,      ///< Enum value for Spades
            Club        ///< Enum value for Clubs
        };

        /** \class Value
          * \brief Enum for card values
          */
        enum class Value {
            Ace,     ///< Enum value for an ace
            Two,     ///< Enum value for a two
            Three,   ///< Enum value for a three
            Four,    ///< Enum value for a four
            Five,    ///< Enum value for a five
            Six,     ///< Enum value for a six
            Seven,   ///< Enum value for a seven
            Eight,   ///< Enum value for an eight
            Nine,    ///< Enum value for a nine
            Ten,     ///< Enum value for a ten
            Jack,    ///< Enum value for a jack
            Queen,   ///< Enum value for a queen
            King     ///< Enum value for a king
        };

    private:
        /// This card's suit
        Suit suit;
        /// This card's value
        Value value;

        /// A map that maps suits to their string representations
        const static std::map<Suit, std::string> suitNames;
        /// A map that maps values to their string representations
        const static std::map<Value, std::string> valueNames;

        /// A list of all possible suits
        const static std::vector<Suit> suits;
        /// A list of all possible values
        const static std::vector<Value> values;

    public:

        /** \brief Constructor
          * \param  suit_  The suit of this card
          * \param  value_  The value of this card
          */
        Card(Suit suit_, Value value_) : suit(suit_), value(value_) {}

        /** \brief Returns this card's suit
          * \return The suit of the card
          */
        Suit getSuit() const {
            return suit;
        }

        /** \brief Returns this card's value
          * \return The value of this card
          */
        Value getValue() const {
            return value;
        }

        /** \brief Returns a list of all suits
          * \return The list of suits
          */
        static const std::vector<Suit>& getSuits() {
            return suits;
        }

        /** \brief Returns a list of all values
          * \return The list of values
          */
        static const std::vector<Value>& getValues() {
            return values;
        }

        /// Output operator for Value
        friend std::ostream& operator<<(std::ostream& os, const Value& value) {
            os << valueNames.at(value);
            return os;
        }

        /// Output operator for Suit
        friend std::ostream& operator<<(std::ostream& os, const Suit& value) {
            os << suitNames.at(value);
            return os;
        }

        /// Output operator for Card
        friend std::ostream& operator<<(std::ostream& os, const Card& card) {
            os << card.getValue() << " of " << card.getSuit();
            return os;
        }
};
