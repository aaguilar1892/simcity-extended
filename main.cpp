#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mapGen.h"
#include "storm.h"
using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    int timeLimit;
    int refreshRate; //Variables for max # time steps & how often time steps are printed to the screen
    
    int workers = 0;
    int goods = 0; //Variables for # available workers & goods
    int totalPollution = 0;
    Zone myZone;

    int xmax = 0;
    int ymax = 0; //Variables for maximum value of x & y coordinates of city
    
    list<Zone> mainList; //List of all zones
    
    InitializeSim(mainList, timeLimit, refreshRate, xmax, ymax); //Initializes mainList, timeLimit, refreshRate, & zone coordinates
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

        //storm simulation
        cout<<endl;
        bool severesimu= false;
        severesimu= storm(mainList);
        if(severesimu){
            cout<<"severe"<<endl;
            severe(mainList);
        }
        cout<<endl;
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
