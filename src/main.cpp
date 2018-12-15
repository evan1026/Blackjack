#include <iostream>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Game.h"

std::string printHandString(const Hand& hand);
void printGameState(const Game& game);
void printStatus(const Game& game);
bool yesNoPrompt(std::string prompt);

int main() {
    std::cout << "=====================================" << std::endl;
    std::cout << "***           Welcome to          ***" << std::endl;
    std::cout << "*** evan1026's CLI blackjack game ***" << std::endl;
    std::cout << "=====================================" << std::endl;

    std::srand(std::time(0));

    bool playing = true;

    while (playing) {
        std::cout << std::endl;
        std::cout << "Initializing... ";

        Game game;
        game.start();

        std::cout << "Done!" << std::endl;
        std::cout << std::endl;

        while (game.isPlaying()) {
            printStatus(game);

            bool hit = yesNoPrompt("Hit");
            if (hit) {
                game.hit();
            } else {
                game.stay();
            }
        }

        printStatus(game);

        if (game.isWin()) {
            std::cout << "You win!" << std::endl;
        } else if (game.isLose()) {
            if (game.isBusted()) {
                std::cout << "Busted! ";
            }
            std::cout << "You lose!" << std::endl;
        } else {
            std::cout << "INVALID GAME STATE" << std::endl;
            printGameState(game);
        }

        playing = yesNoPrompt("Play again");
    }
}

bool yesNoPrompt(std::string prompt) {
    int answer = -1;
    while (answer == -1) {
        std::cout << prompt << " (y/n)? ";
        std::cout.flush();

        std::string line;
        std::getline(std::cin, line);
        if (line == "y") {
            answer = 1;
        } else if (line == "n") {
            answer = 0;
        }
    }

    return answer;
}

void printGameState(const Game& game) {
    std::cout << "Game State: " << std::endl;
    std::cout << "\tisStarted: " << game.isStarted() << std::endl;
    std::cout << "\tisWin:     " << game.isWin()     << std::endl;
    std::cout << "\tisLose:    " << game.isLose()    << std::endl;
    std::cout << "\tisBusted:  " << game.isBusted()  << std::endl;
    std::cout << "\tisPlaying: " << game.isPlaying() << std::endl;
}

void printStatus(const Game& game) {
    std::string playerHandString = printHandString(game.getPlayerHand());
    std::string dealerHandString = printHandString(game.getDealerHand());

    int maxSize = std::max(playerHandString.size(), dealerHandString.size());

    std::cout << "Player Hand: " << std::setw(maxSize) << std::left << playerHandString <<
        "\tValue: " << game.getPlayerHand().getValue() << std::endl;

    std::cout << "Dealer Hand: " << std::setw(maxSize) << std::left << dealerHandString <<
        "\tValue: " << game.getDealerHand().getValue() << std::endl;

#ifdef DEBUG
    printGameState(game);
#endif

    std::cout << std::endl;
}

std::string printHandString(const Hand& hand) {
    std::stringstream ss;
    ss << "{";
    for (auto& card : hand.getCards()) {
        ss << card << ", ";
    }
    ss << "\b\b}";

   return ss.str();
}
