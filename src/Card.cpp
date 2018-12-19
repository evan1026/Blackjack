#include "Card.h"

/// Map from Suits to their string representations
const std::map<Card::Suit, std::string>
Card::suitNames = {
    {Suit::Heart, "Hearts"},
    {Suit::Diamond, "Diamonds"},
    {Suit::Spade, "Spades"},
    {Suit::Club, "Clubs"}
};

/// Map from Values to their string representations
const std::map<Card::Value, std::string>
Card::valueNames = {
    {Value::Ace, "Ace"},
    {Value::Two, "Two"},
    {Value::Three, "Three"},
    {Value::Four, "Four"},
    {Value::Five, "Five"},
    {Value::Six, "Six"},
    {Value::Seven, "Seven"},
    {Value::Eight, "Eight"},
    {Value::Nine, "Nine"},
    {Value::Ten, "Ten"},
    {Value::Jack, "Jack"},
    {Value::Queen, "Queen"},
    {Value::King, "King"}
};

/// List of all Suits
const std::vector<Card::Suit>
Card::suits = {
    Suit::Heart,
    Suit::Diamond,
    Suit::Spade,
    Suit::Club
};

/// List of all values
const std::vector<Card::Value>
Card::values = {
    Value::Ace,
    Value::Two,
    Value::Three,
    Value::Four,
    Value::Five,
    Value::Six,
    Value::Seven,
    Value::Eight,
    Value::Nine,
    Value::Ten,
    Value::Jack,
    Value::Queen,
    Value::King
};
