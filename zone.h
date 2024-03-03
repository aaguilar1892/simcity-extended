#include <iostream>

class Zone{

	private:

		int x;
		int y; //x & y coordinates of zone
		char zoneType;

		int numPop;
		int numWorkers;
		int numGoods; //Variables for population of zone, available workers, & goods

	public:

		void Setx(int xCoord);
		void Sety(int yCoord);
		void SetZoneType(char type);
		int Getx();
		int Gety();
		char GetZoneType(); //Get & sets for zone coordinates and type

		void SetPop(int pop);
		void SetWorkers(int workers);
		void SetGoods(int goods);
		int GetPop();
		int GetWorkers();
		int GetGoods(); //Get and sets for zone population, workers, and goods

		void CheckAdjZones(char type);
};

