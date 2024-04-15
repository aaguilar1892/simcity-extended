#ifndef PAUSEPLAY_H
#define PAUSEPLAY_H

#include <iostream>
#include <string>

class Control {
public:
    enum class Command { Continue, Pause, Quit };

    Command getUserCommand();

    void waitForPlay();
};


#endif // PAUSEPLAY_H