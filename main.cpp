#include <iostream>
#include "output.h"
using namespace std;

int main(){

    int timeLimit;
    int refreshRate;

    int workers = 0;
    int goods = 0; //Variables for # available workers & goods

    list<Zone> mainList; //List of all zones
    list<Zone> resident;
    list<Zone> industrial;
    list<Zone> commerical;

    InitializeSim(mainList, timeLimit, refreshRate); //Initializes mainList, timeLimit, refreshRate, & zone coordinates
    SetAdjLists(mainList); //Creates adjacency lists for each zone
    setZone(mainList, resident, industrial, commerical);
    
    //Test time limit & refresh rate assigned correctly
    /*
    cout << "Time limit: " << timeLimit << endl;
    cout << "Refresh rate: " << refreshRate << endl;
    */
    //Test zone coordinates assigned correctly
        
    /*for(auto it : resident){

        cout << it.Getx() << ", " << it.Gety() << endl;
    }*/
    
    int changed=0;

    for(int i = 0; i < timeLimit; ++i){
        changed=0;
        
        for(auto it : mainList){
            it.CheckAdjZones(workers, goods, changed); //Analyze zone
        }
        
        if(changed == 0){
            break;
        }
        
        //Print output for current time step if appropriate for specified refresh rate
        if(i%refreshRate == 0){
            printOutput(mainList);
        }
        cout<<"Time Step: "<<i+1<<endl;
        cout<<"Available Workers: "<<workers<<endl;
        cout<<"Available Goods: "<<goods<<endl;

    } //Analyze every zone during each time step until time limit is reached
    
    //final print
    printOutput(mainList);
    
    //print final population of each zone
    printPop(resident, industrial, commerical);
    
    //print area wanted by student and get coordinates
    printArea(mainList,resident, industrial, commerical);
    
    return 0;
}
