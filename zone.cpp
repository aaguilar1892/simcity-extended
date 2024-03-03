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

//Set and gets for zone population, workers, goods
void Zone::SetPop(int pop){
	numPop = pop;
}

void Zone::SetWorkers(int workers){
	numWorkers = workers;
}

void Zone::SetGoods(int goods){
	numGoods = goods;
}

int Zone::GetPop(){
	return numPop;
}

int Zone::GetWorkers(){
	return numWorkers;
}

int Zone::GetGoods(){
	return numGoods;
}

//Function for analyzing zone
void Zone::CheckAdjZones(char type){
	
}
