#include "PausePlay.h"

Control::Command Control::getUserCommand() {
    std::string input;
    std::cout << "\n[Continue, Pause, Quit]: ";
    std::getline(std::cin, input);
       
    if (input == "Pause") return Control::Command::Pause;
    else if (input == "Quit") return Control::Command::Quit;
    else return Control::Command::Continue;
}

void Control::waitForPlay() {
    std::string input;
    do {
        std::cout << "Type 'Play' to continue: ";
        std::getline(std::cin, input);
    } while (input != "Play");
}
