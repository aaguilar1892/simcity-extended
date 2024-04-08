#include "PausePlay.h"

// Function to prompt user to continue or pause
void promptContinue() {
    std::string userInput;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Simulation paused. Enter 'c' to continue or 'p' to pause again: ";
        std::cin >> userInput;

        if (userInput == "c") {
            // User chose to continue
            validInput = true;
        } else if (userInput == "p") {
            // User chose to pause again, just loop until 'c' is entered
            validInput = false;
        } else {
            std::cout << "Invalid input. Please enter 'c' to continue or 'p' to pause again.\n";
        }
    }
}