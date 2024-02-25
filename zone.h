#include <iostream>

class Zone{

	private:

		int x;
		int y; //x & y coordinates of zone
		char zoneType;


	public:

		void Setx(int xCoord);
		void Sety(int yCoord);
		void SetZoneType(char type);
		int Getx();
		int Gety();
		char GetZoneType();
};

