#include <iostream>
#include <list>
#include "WorkersAndGoods.h"

using namespace std;
class Zone{

	private:

		int x;
		int y; //x & y coordinates of zone

		char zoneType;
		int numPop; //Variables for zone population & type

		//Add list variable for adjacent zones
		list<Zone> adjZone;

	public:

		void Setx(int xCoord);
		void Sety(int yCoord);
		void SetZoneType(char type);
		int Getx();
		int Gety();
		char GetZoneType(); //Get & sets for zone coordinates and type

		int GetPop(); //Get zone population

		void CheckAdjZones(int workers, int goods, int changed);

		//Add default constructor for zone w/population 0
};

