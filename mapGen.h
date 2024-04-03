#include "output.h"
#include <ctime>
#include <cstdlib>

void EnvironmentGen(list<Zone> &mainList); //Sets environment type
void InitializeMap(list<Zone> &mainList, int &xmax, int &ymax); //Initializes surrounding environment
