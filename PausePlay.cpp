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

Control::Command getUserCommand() {
    std::string input;
    std::cout << "\n[Continue, Pause, Quit]: ";
    std::getline(std::cin, input);
       
    if (input == "Pause") return Control::Command::Pause;
    else if (input == "Quit") return Control::Command::Quit;
    else return Control::Command::Continue;
}

void waitForPlay() {
    std::string input;
    do {
        std::cout << "Type 'Play' to continue: ";
        std::getline(std::cin, input);
    } while (input != "Play");
}

/*cout << "Enter 'play' to continue, 'pause' to pause, or 'quit' to end simulation: ";
        string userInput;
        cin >> userInput;

        if (userInput == "pause") {
            cout << "Simulation paused. Enter 'play' to resume.";
            do {
                cin >> userInput;
            } while (userInput != "play");
            cout << "Resuming simulation..." << endl;
        } else if (userInput == "quit") {
            cout << "Simulation ended by user." << endl;
            break; // Exit the simulation loop
        }*/

