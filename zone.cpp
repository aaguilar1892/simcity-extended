#include "zone.h"

//Set and gets for zone coordinates and type
void Zone::Setx(int xCoord){
    x = xCoord;
}

void Zone::Sety(int yCoord){
    y = yCoord;
}

void Zone::SetZoneType(char type){
    zoneType = type;
}

int Zone::Getx(){
    return x;
}

int Zone::Gety(){
    return y;
}

char Zone::GetZoneType(){
    return zoneType;
}


//Get zone population
int Zone::GetPop(){
    return numPop;
}

void Zone::SetPop(int pop){
    numPop = pop;
}



//Function for analyzing zone
void Zone::CheckAdjZones(int workers, int goods, int changed){
    
    bool power; //Is the zone adjacent to a powerline?
    int adjPop1; //# adjacent zones w/population >= 1
    int adjPop2; //# adjacent zones w/population >= 2
    int adjPop3; //# adjacent zones w/population >= 3
    int adjPop4; //# adjacent zones w/population >= 4

    if(zoneType == 'C'){

        if(power == true && numPop == 0 && workers >= 1 && goods >= 1){
            ++numPop;
            SetGoods(false, goods);
            SetWorkers(false, workers);
            ++ changed;
        }
        else if(numPop == 0 && adjPop1 >= 1 && workers >= 1 && goods >= 1){
            ++numPop;
            SetGoods(false, goods);
            SetWorkers(false, workers);
            ++ changed;
        }
        else if(numPop == 1 && adjPop1 >= 2 && workers >= 1 && goods >= 1){
            ++numPop;
            SetGoods(false, goods);
            SetWorkers(false, workers);
            ++changed;
        }
        else{}
    } //Check conditions for commercial zone growth
/*
 Outline for industrial and Residential, please keep in ++changed, in all if or else if statements, in else statement do not add changed
    if(zoneType == 'R'){
        if(){
            
            ++changed;
        }else if(){
            
            ++changed;
        }else if(){
            
            ++changed;
        }else{}
        
    } //Check conditions for residential zone growth
    if(zoneType == 'I'){
        if(){
            
            ++changed;
        }else if(){
            
            ++changed;
        }else if(){
            
            ++changed;
        }else{}

    }
 *///Check conditions for industrial zone growth
}
void Zone :: AdjacencyList(vector<Zone> &mainList){
    for(auto it : mainList){
        for(auto iter : mainList){
            if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() -1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() -1)){
                adjZones.push_back(iter);
            }
        }
    }
}
