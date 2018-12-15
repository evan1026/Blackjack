#include <iostream>
#include <algorithm>
#include <ctime>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

void printPlayerHand(const Hand& hand);

int main() {
    std::srand(std::time(0));

    bool playing = true;
    Deck deck;
    Hand playerHand;
    Hand dealerHand;

    while (playing) {
        dealerHand.clear();
        playerHand.clear();
        deck.shuffle();

        playerHand.addCard(deck.draw());
        playerHand.addCard(deck.draw());
        dealerHand.addCard(deck.draw());
        dealerHand.addCard(deck.draw());

        printPlayerHand(playerHand);
        std::cout << "Dealer Hand: {" << dealerHand.getCards().at(0) << ", <Hidden>}" << std::endl;
        std::cout << "" << std::endl;

        bool done = false;
        while (!done) {
            std::cout << "Hit [y/n]? ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "y") {
                playerHand.addCard(deck.draw());
                printPlayerHand(playerHand);
                if (playerHand.getValue() > 21) {
                    std::cout << "You lose!" << std::endl << std::endl << std::endl;
                    done = true;
                }
            } else if (input == "n") {
                done = true;
            }
        }
    }
}

void printPlayerHand(const Hand& hand) {
    std::cout << "Player Hand: {";
    for (auto& card : hand.getCards()) {
        std::cout << card << ",";
    }
    std::cout << "\b}" << std::endl;
}
