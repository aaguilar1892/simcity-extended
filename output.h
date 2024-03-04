#include <iostream>
#include <list>
#include <vector>
#include "initialization.h"
using namespace std;


void printOutput(list<Zone> &mainList);

void printArea(list<Zone> &mainList, list<Zone> &resident,list<Zone> &industrial,list<Zone> &commerical);

void setZone(list<Zone> &mainList, list<Zone> &resident,list<Zone> &industrial,list<Zone> &commerical);

void printPop(list<Zone> &resident,list<Zone> &industrial,list<Zone> &commerical);
