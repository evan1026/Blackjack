#include "Card.h"

const std::map<Card::Suit, std::string>
Card::suitNames = {
    {Suit::Heart, "Hearts"},
    {Suit::Diamond, "Diamonds"},
    {Suit::Spade, "Spades"},
    {Suit::Club, "Clubs"}
};

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

const std::vector<Card::Suit>
Card::suits = {
    Suit::Heart,
    Suit::Diamond,
    Suit::Spade,
    Suit::Club
};

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
