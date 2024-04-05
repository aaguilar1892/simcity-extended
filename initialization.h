#ifndef initialization_h
#define initialization_h
#include <iostream>
#include <fstream>
#include <list>
#include "zone.h"
using namespace std;

void InitializeSim(list<Zone> &mainList, int &timeLimit, int &refreshRate, int &xmax, int &ymax); //Initializes mainList, time limit, refresh rate, and zone coordinates
#endif
