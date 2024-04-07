#include <iostream>
#include "output.h"
using namespace std;

void BuildMenu(int totalPop, int &builtZones, list<Zone> &mainList); //Outputs build menu
void Build(char choice, int totalPop, int &builtZones, list<Zone> &mainList, int xCoord, int yCoord); //Builds new city zones
bool ZoneValidity(int xCoord, int yCoord, list<Zone> mainList); //Checks if zone can be developed
void ChangeZoneType(char newType, int xCoord, int yCoord, list<Zone> &mainList); //Changes environment zone to city zone
