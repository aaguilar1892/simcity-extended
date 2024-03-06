#include <iostream>
#include "output.h"
using namespace std;

void ResetChanges(list<Zone> &mainList){

    for(auto it : mainList){
        it.SetPrevChanged(false);
    }
}

int main(){
    
    int timeLimit;
    int refreshRate;
    
    int workers = 0;
    int goods = 0; //Variables for # available workers & goods
    
    list<Zone> mainList; //List of all zones
    
    InitializeSim(mainList, timeLimit, refreshRate); //Initializes mainList, timeLimit, refreshRate, & zone coordinates
    
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
        ResetChanges(mainList);
        
        for(auto& it : mainList){
            it.CheckAdjZones(workers, goods, changed, mainList);//Analyze zone
        }
        
        //if there is no change inbetween it stops the loop
        if(changed == 0){
            break;
        }
        
        //Print output for current time step if appropriate for specified refresh rate
        if(i%refreshRate == 0){
            printOutput(mainList);
        }

        workers = CalcWorkers(mainList, workers);
        goods = CalcGoods(mainList, workers); //Calculate total # available workers & goods

    cout<<"Time Step: "<<i+1<<endl;
    cout<<"Available Workers: "<<workers<<endl;
    cout<<"Available Goods: "<<goods<<endl;
}

    //Analyze every zone during each time step until time limit is reached
    
    
    //final print
    printOutput(mainList);
    //print final population of each zone
    printPop(mainList);
    
    //print area wanted by student and get coordinates
    printArea(mainList);

    return 0;
}
