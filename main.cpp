#include <iostream>
#include "initialization.h"
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
    

    return 0;
}
