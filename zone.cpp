#include "zone.h"

//Default constructor for zone objects
Zone::Zone(){
    numPop = 0;
    numWorkers = 0;
    numGoods = 0;
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

//Function for analyzing commercial zones
void Zone::CheckAdjZonesC(int &workers, int &goods, int &changed, list<Zone> &mainList){
    
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

    //Check conditions for commercial zone growth
    if(zoneType == 'C'){

        if(power == true && numPop == 0 && workers >= 1 && goods >= 1){
            ++numPop;
            --goods;
            --numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 0 && adjPop1 >= 1 && workers >= 1 && goods >= 1){
            ++numPop;
            --goods;
            --numWorkers;
            ++changed;
            prevChanged = true;
        }
        else if(numPop == 1 && adjPop1 >= 2 && workers >= 1 && goods >= 1){
            ++numPop;
            --goods;
            --numWorkers;
            ++changed;
            prevChanged = true;
        }
        else{}
    } 
}

//Function for analyzing residential zones
void Zone::CheckAdjZonesR(int &workers, int &goods, int &changed, list<Zone> &mainList){
    
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

    //Check conditions for residential zone growth
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
    } 
}

//Function for analyzing industrial zones
void Zone::CheckAdjZonesI(int &workers, int &goods, int &changed, list<Zone> &mainList){
    
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
                pollutionLevel =numPop; //Pollution equal to population
            }
        }
    }

    //Check conditions for industrial zone growth
    if(zoneType == 'I'){
        if(numPop == 0 && power == true && workers >= 2){
            ++numPop;
            workers = 0;
            ++goods;
            ++changed;
            prevChanged = true;
            pollutionLevel =numPop; //Pollution equal to population
        }else if(numPop == 0 && adjPop1 >= 1 && workers >= 2){
            ++numPop;
            workers = 0;
            ++goods;
            ++changed;
            prevChanged = true;
            pollutionLevel =numPop; //Pollution equal to population
        }else if(numPop == 1 && adjPop1 >= 2 && workers >= 2){
            ++numPop;
            workers = 0;
            ++goods;
            ++changed;
            prevChanged = true;
            pollutionLevel =numPop; //Pollution equal to population
        }else if(numPop == 2 && adjPop2 >= 4 && workers >= 2){
            ++numPop;
            workers = 0;
            ++goods;
            ++changed;
            pollutionLevel =numPop; //Pollution equal to population
        }else{}
    }
}

//Set zone to changed or unchanged during the current time step
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

//Set pollution level of zone
void Zone::setPollutionLevel(int pollution){
    pollutionLevel = pollution;
}

//Get pollution level of zone
int Zone::getPollutionLevel(){
    return pollutionLevel;
}

void Zone::spreadPollution(list<Zone> &mainList){
    if(zoneType == 'I' && numPop > 0){ // If the zone is industrial and populated
        for(auto &zone : mainList){
            // Calculate distance between current zone and each zone in mainList
            int dx = abs(zone.Getx() - x);
            int dy = abs(zone.Gety() - y);
            //int distance = max(dx, dy);
            if((dx == 1 && dy <= 1) || (dy == 1 && dx <= 1)){ // Adjacent cells
                //int decayFactor = 2;
                int spreadPollution = pollutionLevel - 1; // Pollution spreads at one less unit
                zone.setPollutionLevel(zone.getPollutionLevel() + spreadPollution);
            }
        }
    }
}
