#include <iostream>
#include <list>
#include <string>
#include "WorkersAndGoods.h"

using namespace std;
class Zone{

    private:

        int x;
        int y; //x & y coordinates of zone

        char zoneType;
        int numPop; //Variables for zone population & type

        bool prevChanged;

    public:

        void Setx(int xCoord);
        void Sety(int yCoord);
        void SetZoneType(char type); //Sets for zone coordinates and type
        void SetPop(int pop); //Set zone population
        void SetPrevChanged(bool change);

        int Getx();
        int Gety();
        char GetZoneType(); //Gets for zone coordinates and type
        int GetPop(); //Get zone population
        

        void CheckAdjZones(int workers, int goods, int &changed, list<Zone> &mainList); //Analyze zones
        Zone(); //Default constructor for zone objects
};
