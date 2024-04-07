#include <iostream>
#include "output.h"
using namespace std;

void BuildMenu(int totalPop, int &builtZones, list<Zone> &mainList);
void Build(char choice, int totalPop, int &builtZones, list<Zone> &mainList, int xCoord, int yCoord);
bool ZoneValidity(int xCoord, int yCoord, list<Zone> mainList);
void ChangeZoneType(char newType, int xCoord, int yCoord, list<Zone> &mainList);
