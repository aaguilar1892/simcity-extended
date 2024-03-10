#include <iostream>
#include "output.h"
using namespace std;

int main(){
    
    int timeLimit;
    int refreshRate;
    
    int workers = 0;
    int goods = 0; //Variables for # available workers & goods
    Zone myZone;
    
    list<Zone> mainList; //List of all zones
    
    InitializeSim(mainList, timeLimit, refreshRate); //Initializes mainList, timeLimit, refreshRate, & zone coordinates
    
    int changed=0; //# of changes in time step

    printOutput(mainList); //Output initial state
    cout << "--Initial State --" << endl;
    cout << endl;
    
    //Analyze every zone during each time step until time limit is reached
    for(int i = 0; i < timeLimit; ++i){
        changed=0;
        
        //Analyze zone
        for(auto& it : mainList){
            it.CheckAdjZones(workers, goods, changed, mainList);
        }

        //Reset all zones to unchanged
        for(auto& it : mainList){
            it.SetPrevChanged(false);
        } 
        
        //if there is no change inbetween it stops the loop
        if(changed == 0){
            break;
        }
        
        //Print output for current time step if appropriate for specified refresh rate
        if(i%refreshRate == 0){
            printOutput(mainList);
        }

        //Calculate total # available workers & goods
        workers = myZone.CalcWorkers(mainList, workers);
        goods = myZone.CalcGoods(mainList, goods); 

    cout<<"Time Step: "<<i+1<<endl;
    cout<<"Available Workers: "<<workers<<endl;
    cout<<"Available Goods: "<<goods<<endl;
    cout<<endl;
}   
    
    //final print
    printOutput(mainList);
    //print final population of each zone
    printPop(mainList);
    
    //print area wanted by student and get coordinates
    printArea(mainList);

    return 0;
}
