#include "zone.h"

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
