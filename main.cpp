#include <iostream>
#include "output.h"
using namespace std;

int main(){

    int timeLimit;
    int refreshRate;

    int workers = 0;
    int goods = 0; //Variables for # available workers & goods

    list<Zone> mainList;
    list<Zone> resident;
    list<Zone> industrial;
    list<Zone> commerical;
    InitializeSim(mainList, timeLimit, refreshRate);
    setZone(mainList, resident, industrial, commerical);
    printOutput(mainList);
    printArea(mainList);


    //Test time limit & refresh rate assigned correctly
    /*
    cout << "Time limit: " << timeLimit << endl;
    cout << "Refresh rate: " << refreshRate << endl;
    */
    //Test zone coordinates assigned correctly
    
    /*for(auto it : mainList){

        cout << it.Getx() << ", " << it.Gety() << endl;
    }*/

    for(int i = 0; i < timeLimit; ++i){

        for(auto it : mainList){
            it.CheckAdjZones(workers, goods); //Analyze zone
        }

        //Print output for current time step if appropriate for specified refresh rate
    } //Analyze every zone during each time step until time limit is reached

    return 0;
}
