#include "zone.h"

//Default constructor for zone objects
Zone::Zone(){
    numPop = 0;
    numWorkers = 0;
    numGoods = 0;
    pollutionLevel = 0;
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


//Set and get zone population, # workers, & # goods
int Zone::GetPop(){
    return numPop;
}

void Zone::SetPop(int pop){
    numPop = pop;
}

int Zone::GetWorkers(){
    return numWorkers;
}

int Zone::GetGoods(){
    return numGoods;
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

                    if((iter.GetPop() >= 4 && iter.prevChanged == false) || (iter.prevChanged == true && iter.GetPop() - 1 >= 4)){
                            ++adjPop4;
                    }
                    else if((iter.GetPop() >= 3 && iter.prevChanged == false) || (iter.prevChanged == true && iter.GetPop() - 1 >= 3)){
                            ++adjPop3;
                    }
                    else if((iter.GetPop() >= 2 && iter.prevChanged == false) || (iter.prevChanged == true && iter.GetPop() - 1 >= 2)){
                            ++adjPop2;
                    }
                    else if((iter.GetPop() >= 1 && iter.prevChanged == false) || (iter.prevChanged == true && iter.GetPop() - 1 >= 1)){
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
            --numGoods;
            --numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 0 && adjPop1 >= 1 && workers >= 1 && goods >= 1){
            ++numPop;
            --numGoods;
            --numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 1 && adjPop1 >= 2 && workers >= 1 && goods >= 1){
            ++numPop;
            --numGoods;
            --numWorkers;
            ++changed;
            prevChanged = true;
        }
        else{}
    } //Check conditions for commercial zone growth

 //Outline for industrial and Residential, please keep in ++changed, in all if or else if statements, in else statement do not add changed
    if(zoneType == 'R'){
        if(power == true && numPop == 0){
            ++numPop;
            ++numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 0 && adjPop1 >= 1){
            ++numPop;
            ++numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 1 && adjPop1 >= 2){
            ++numPop;
            ++numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if (numPop == 2 && adjPop2 >= 4){
            ++numPop;
            ++numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 3 && adjPop3 >= 6){
            ++numPop;
            ++numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 4 && adjPop4 >= 8){
            ++numPop;
            ++numWorkers;
            ++changed;
            prevChanged = true;
        }
        else {}
    } //Check conditions for residential zone growth

    if(zoneType == 'I'){
        bool power = false;
        // Search for adjacent power sources
        for(auto iter: mainList) {
            // Existing Adjacent Zone Checks ...
            if (iter.GetZoneType() == 'T' || iter.GetZoneType() == 'P') {
                power = true;
            }
        }

        if ((power || adjPop1 >= 1) && numPop == 0 && workers >= 2){
            ++numPop;
            --workers;
            ++changed;
            prevChanged = true;
            pollutionLevel = numPop;  // Set initial pollution
        } else if(adjPop1 >= 2 && numPop == 1 && workers >= 2){
            ++numPop;
            --workers;
            ++changed;
            prevChanged = true;
            pollutionLevel = numPop;
        } else if(adjPop2 >= 4 && numPop == 2 && workers >= 2){
            ++numPop;
            --workers;
            ++changed;
            prevChanged = true;
            pollutionLevel = numPop;
        } else {
            pollutionLevel = numPop; // Update even if no growth
        }
    }
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

//Calculate total workers & goods
int Zone::CalcWorkers(list<Zone> mainList, int workers){

    for(auto it : mainList){
        workers = workers + it.GetWorkers();
    }
    return workers;
}

int Zone::CalcGoods(list<Zone> mainList, int goods){

    for(auto it: mainList){
        goods = goods + it.GetGoods();
    }
    return goods;
}

void Zone::SetPollutionLevel(int level) {
    pollutionLevel = level;
}

int Zone::GetPollutionLevel() {
    return pollutionLevel;
}

void Zone::spreadPollution(Zone &source, list<Zone> &mainList) {
    int x = source.Getx();
    int y = source.Gety();
    int pollution = source.GetPollutionLevel();

    // Iterate in a 3x3 square around the source zone
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int adjX = x + dx;
            int adjY = y + dy;

            // Check if adjacent cell is within bounds
            if (adjX >= 0 && adjX < mainList.front().Getx() && adjY >= 0 && adjY < mainList.front().Gety()) {
                for (auto &zone : mainList) {
                    if (zone.Getx() == adjX && zone.Gety() == adjY) {
                        // Adjust pollution based on distance
                        int spreadAmount = max(0, pollution - abs(dx) - abs(dy));
                        zone.SetPollutionLevel(zone.GetPollutionLevel() + spreadAmount);
                    }
                }
            }
        }
    }
}