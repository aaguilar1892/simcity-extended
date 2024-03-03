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

//Function for analyzing zone
void Zone::CheckAdjZones(int workers, int goods){
	
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
		}
		else if(numPop == 0 && adjPop1 >= 1 && workers >= 1 && goods >= 1){
			++numPop;
			SetGoods(false, goods);
			SetWorkers(false, workers);
		}
		else if(numPop == 1 && adjPop1 >= 2 && workers >= 1 && goods >= 1){
			++numPop;
			SetGoods(false, goods);
			SetWorkers(false, workers);
		}
		else{}
	} //Check conditions for commercial zone growth

	if(zoneType == 'R'){} //Check conditions for residential zone growth
	if(zoneType == 'I'){} //Check conditions for industrial zone growth
}
