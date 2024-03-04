#ifndef output_hpp
#define output_hpp
#include <iostream>
#include <list>
#include <vector>
#include "initialization.h"
using namespace std;


void printOutput(list<Zone> &mainList);

void printArea(list<Zone> &mainList);

void setZone(list<Zone> &mainList, list<Zone> &resident,list<Zone> &industrial,list<Zone> &commerical);


#endif /* output_hpp */
