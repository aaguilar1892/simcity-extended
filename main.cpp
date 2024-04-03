#include <iostream>
#include "output.h"
using namespace std;

int main(){
    
    int timeLimit;
    int refreshRate; //Variables for max # time steps & how often time steps are printed to the screen
    
    int workers = 0;
    int goods = 0; //Variables for # available workers & goods
    int totalPollution = 0;
    Zone myZone;
    
    list<Zone> mainList; //List of all zones
    
    InitializeSim(mainList, timeLimit, refreshRate); //Initializes mainList, timeLimit, refreshRate, & zone coordinates
    InitializeMap(mainList, xmax, ymax); //Initialize surrounding map
    
    int changed=0; //# of changes in time step

    //Output initial state
    printOutput(mainList); 
    cout << "--Initial State --" << endl;
    cout << endl;
    
    //Analyze every zone during each time step until time limit is reached
    for(int i = 0; i < timeLimit; ++i){
        changed=0;
        
        //Analyze commercial, then industrial, then residential zones
        for(auto& it : mainList){
            it.CheckAdjZonesC(workers, goods, changed, mainList);
        }

        for(auto& it : mainList){
            it.CheckAdjZonesI(workers, goods, changed, mainList);
        }

        for(auto& it : mainList){
            it.CheckAdjZonesR(workers, goods, changed, mainList);
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

        cout<<"Time Step: "<<i+1<<endl;
        cout<<"Available Workers: "<<workers<<endl;
        cout<<"Available Goods: "<<goods<<endl;
        cout<<endl;

        // Spread pollution 
        for(auto& it : mainList){
            it.spreadPollution(mainList);
        }
    }

    // Update totalPollution
    totalPollution = 0;
    for (auto& it : mainList) {
        totalPollution += it.getPollutionLevel();
    }

    //final print
    printOutput(mainList);

    //print final population of each zone
    printPop(mainList);
    
    //print area wanted by student and get coordinates
    printArea(mainList);

    //print pollution
    printPollution(mainList);
    
    cout<< "Total Pollution: "<<totalPollution<<endl;

    return 0;
}
