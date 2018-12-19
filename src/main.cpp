#include <iostream>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Game.h"

std::string generateHandString(const Hand& hand, bool hiddenDealerHand);
void printGameState(const Game& game);
void printStatus(const Game& game);
bool yesNoPrompt(const std::string& prompt);
void doHitLoop(Game& game);
void printEndStatus(const Game& game);

/*
 * Main function
 */
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

        doHitLoop(game);

        std::cout << std::endl;
        std::cout << "Final results:" << std::endl;

        printEndStatus(game);

        playing = yesNoPrompt("Play again");
    }
}

/** \brief   Prints a yes or no prompt and returns what the user inputs
  * \param   prompt  The prompt for the user to respond to
  * \return  true if the user says yes or false if the user says no
  *
  * This function takes the prompt and prints it in the format "prompt (y/n)?"
  * and then waits for the user to input either a y or an n and press enter.
  * If the user inputs something other than the two valid inputs, the function
  * will repeat the prompt until the user decides to cooperate. If the user
  * enters a y, the function returns true. Otherwise, it returns false.
  */
bool yesNoPrompt(const std::string& prompt) {
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

/** \brief   Prints behind-the-scenes information about the state of the game
  * \param   game  The game to print information about
  *
  * This function prints all of the is*() methods within the game to show the
  * full state of the game at whatever moment it is called. This is only
  * meant for debugging purposes, but need not be compiled in debug mode to
  * be called.
  */
void printGameState(const Game& game) {
    std::cout << "Game State: " << std::endl;
    std::cout << "\tisStarted: " << game.isStarted() << std::endl;
    std::cout << "\tisWin:     " << game.isWin()     << std::endl;
    std::cout << "\tisLose:    " << game.isLose()    << std::endl;
    std::cout << "\tisBusted:  " << game.isBusted()  << std::endl;
    std::cout << "\tisPlaying: " << game.isPlaying() << std::endl;
}

/** \brief   Prints all relevant information for the player to the console about the game
  * \param   game  The game to print the status of
  *
  * Prints the following information for the player:
  *     1) Player hand & value
  *     2) Dealer hand & value (if applicable)
  *     3) Full game state (if compiled in debug mode)
  *
  * If the player has not yet chosen to stay, the dealer's hand will only show the first
  * card, and its value will be hidden. Otherwise, the dealer's full hand and value will
  * be shown.
  */
void printStatus(const Game& game) {
    std::string playerHandString = generateHandString(game.getPlayerHand(), false);
    std::string dealerHandString = generateHandString(game.getDealerHand(), game.isPlaying()); //If we are still playing, the user has not decided to stay yet

    int maxSize = std::max(playerHandString.size(), dealerHandString.size());

    std::cout << "Player Hand: " << std::setw(maxSize) << std::left << playerHandString <<
        "\tValue: " << game.getPlayerHand().getValue() << std::endl;

    std::cout << "Dealer Hand: " << std::setw(maxSize) << std::left << dealerHandString;
    if (!game.isPlaying()) {
        std::cout << "\tValue: " << game.getDealerHand().getValue() << std::endl;
    }

#ifdef DEBUG
    printGameState(game);
#endif

    std::cout << std::endl;
}

/** \brief   Generates a string for the given hand
  * \param   hand              The hand to print
  * \param   hiddenDealerHand  Whether to hide the dealer's hand
  * \return  A string representing the hand
  *
  * This function takes in a hand and generates a string that can be
  * printed to the console that represents that hand. The format is
  * "{card1, card2, ..., cardn}". If the hiddenDealerHand flag is set,
  * all cards except the first one will display as "<Hidden>".
  */
std::string generateHandString(const Hand& hand, bool hiddenDealerHand) {
    std::stringstream ss;
    ss << "{";

    bool firstCard = true;
    for (auto& card : hand.getCards()) {
        if (hiddenDealerHand && !firstCard) {
            ss << "<Hidden>, ";
        } else {
            ss << card << ", ";
        }
        firstCard = false;
    }

    ss << "\b\b}";

   return ss.str();
}

/** \brief   Runs the loop that keeps asking the user if they want to hit or stay
  * \param   game  The game we are running
  *
  * This function simply runs a loop that keeps asking the user if they want to
  * hit or stay. The loop ends when the user busts or they decide to stay.
  */
void doHitLoop(Game& game) {
    while (game.isPlaying()) {
        printStatus(game);

        bool hit = yesNoPrompt("Hit");
        if (hit) {
            game.hit();
        } else {
            game.stay();
        }
    }
}

/** \brief   Prints the status of the game at the end
  * \param   game  The game we are running
  *
  * Prints out the normal game status via printStatus() and then informs the
  * user if they won or lost. If an invalid game state occurs, it will print debug information
  * as well (an invalid state is one in which we have not won, lost, or tied, which will
  * occur if this function is called before the game has ended).
  */
void printEndStatus(const Game& game) {
    printStatus(game);

    if (game.isWin()) {
        std::cout << "You win!" << std::endl;
    } else if (game.isLose()) {
        if (game.isBusted()) {
            std::cout << "Busted! ";
        }
        std::cout << "You lose!" << std::endl;
    } else if (game.isTie()) {
        std::cout << "It's a draw!" << std::endl;
    } else {
        std::cout << "INVALID GAME STATE" << std::endl;
        printGameState(game);
    }
}
