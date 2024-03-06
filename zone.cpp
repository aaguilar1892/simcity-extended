#include "zone.h"

//Default constructor for zone objects
Zone::Zone(){
    numPop = 0;
}

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


//Set and get zone population
int Zone::GetPop(){
    return numPop;
}

void Zone::SetPop(int pop){
    numPop = pop;
}

//Function for analyzing zone
void Zone::CheckAdjZones(int workers, int goods, int &changed, list<Zone> &mainList){
    
    bool power = false; //Is the zone adjacent to a powerline?
    int adjPop1 = 0; //# adjacent zones w/population >= 1
    int adjPop2 = 0; //# adjacent zones w/population >= 2
    int adjPop3 = 0; //# adjacent zones w/population >= 3
    int adjPop4 = 0; //# adjacent zones w/population >= 4

    //Check that current zone isn't empty
    if(zoneType == 'T' || zoneType == 'P'|| zoneType == '#' || zoneType == '-' || zoneType == 'R' || zoneType == 'I' || zoneType == 'C'){

        for(auto iter: mainList){

            //Check that adjacent zone isn't empty
            if(iter.GetZoneType() == 'T' || iter.GetZoneType() == 'P'|| iter.GetZoneType() == '#' || iter.GetZoneType() == '-' || iter.GetZoneType() == 'R' || iter.GetZoneType() == 'I' || iter.GetZoneType() == 'C'){

                //Check that zone is adjacent
                if((iter.Getx() == x || iter.Getx() == x + 1 || iter.Getx() == x - 1) && (iter.Gety() == y || iter.Gety() == y + 1 || iter.Gety() == y - 1) && (!(iter.Getx() == x && iter.Gety() == y))){

                    //If adjacent, analyze for growth conditions
                    if(iter.GetZoneType() == 'T'){
                            power = true;
                    }

                    if(iter.GetPop() >= 4 && iter.prevChanged == false){
                            ++adjPop4;
                    }
                    else if(iter.GetPop() >= 3 && iter.prevChanged == false){
                            ++adjPop3;
                    }
                    else if(iter.GetPop() >= 2 && iter.prevChanged == false){
                            ++adjPop2;
                    }
                    else if(iter.GetPop() >= 1 && iter.prevChanged == false){
                            ++adjPop1;
                    }
                    else{}
                }
            }
        }
    }

    if(zoneType == 'C'){

        if(power == true && numPop == 0 && workers >= 1 && goods >= 1){
            ++numPop;
            SetGoods(false, goods);
            SetWorkers(false, workers);
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 0 && adjPop1 >= 1 && workers >= 1 && goods >= 1){
            ++numPop;
            SetGoods(false, goods);
            SetWorkers(false, workers);
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 1 && adjPop1 >= 2 && workers >= 1 && goods >= 1){
            ++numPop;
            SetGoods(false, goods);
            SetWorkers(false, workers);
            ++changed;
            prevChanged = true;
        }
        else{}
    } //Check conditions for commercial zone growth

 //Outline for industrial and Residential, please keep in ++changed, in all if or else if statements, in else statement do not add changed
    if(zoneType == 'R'){
        if(power == true && numPop == 0){
            ++numPop;
            SetWorkers(true, workers);
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 0 && adjPop1 >= 1){
            ++numPop;
            SetWorkers(true, workers);
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 1 && adjPop1 >= 2){
            ++numPop;
            SetWorkers(true, workers);
            ++changed;
            prevChanged = true;
        }
        else if (numPop == 2 && adjPop2 >= 4){
            ++numPop;
            SetWorkers(true, workers);
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 3 && adjPop3 >= 6){
            ++numPop;
            SetWorkers(true, workers);
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 4 && adjPop4 >= 8){
            ++numPop;
            SetWorkers(true, workers);
            ++changed;
            prevChanged = true;
        } 
        else {}    
    } //Check conditions for residential zone growth
    /*if(zoneType == 'I'){
        if(){
            
            ++changed;
            prevChanged = true;
        }else if(){
            
            ++changed;
            prevChanged = true;
        }else if(){
            
            ++changed;
            prevChanged = true;
        }else{}

    }
 *///Check conditions for industrial zone growth
}

void Zone::SetPrevChanged(bool change){
    prevChanged = change;
}
