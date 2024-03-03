#include <iostream>
#include "output.h"
using namespace std;

int main(){

    int timeLimit;
    int refreshRate;

    list<Zone> mainList;
    InitializeSim(mainList, timeLimit, refreshRate);
    printOutput(mainList);

    //Test time limit & refresh rate assigned correctly
    /*
    cout << "Time limit: " << timeLimit << endl;
    cout << "Refresh rate: " << refreshRate << endl;
    */
    //Test zone coordinates assigned correctly
    
    /*for(auto it : mainList){

        cout << it.Getx() << ", " << it.Gety() << endl;
    }*/
    
    char type; //Character representing zone type

    for(int i = 0; i < timeLimit; ++i){

        for(auto it : mainList){

            type = it.GetZoneType();
            it.CheckAdjZones(type); //Analyze zone
        }

        //Print output for current time step if appropriate for specified refresh rate
    } //Analyze every zone during each time step until time limit is reached

    return 0;
}
