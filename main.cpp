#include "initialization.h"
using namespace std;

int main(){

    int timeLimit;
    int refreshRate;

    list<Zone> mainList;
    InitializeSim(mainList, timeLimit, refreshRate);

    //Test time limit & refresh rate assigned correctly
    /*
    cout << "Time limit: " << timeLimit << endl;
    cout << "Refresh rate: " << refreshRate << endl;
    */
    //Test zone coordinates assigned correctly
    /*
    for(auto it : mainList){

	    cout << it.Getx() << ", " << it.Gety() << endl;
    } 
    */ 

    return 0;
}