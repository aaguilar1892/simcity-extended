#include <iostream>
#include <list>
#include <string>

using namespace std;
class Zone{

    private:

        int x;
        int y; //x & y coordinates of zone

        char zoneType;
        int numPop; 
        int numWorkers;
        int numGoods; //Variables for zone population, type, # available workers & goods

        bool prevChanged;

    public:

        void Setx(int xCoord);
        void Sety(int yCoord);
        void SetZoneType(char type); //Sets for zone coordinates and type
        void SetPop(int pop); //Set zone population
        void SetPrevChanged(bool change); 

        int CalcWorkers(list<Zone> mainList, int workers);
        int CalcGoods(list<Zone> mainList, int goods); //Calculate total # available workers & goods

        int Getx();
        int Gety();
        char GetZoneType(); //Gets for zone coordinates and type
        int GetPop(); //Get zone population
        int GetWorkers();
        int GetGoods(); //Gets for # available workers and goods in a zone
        

        void CheckAdjZones(int workers, int goods, int &changed, list<Zone> &mainList); //Analyze zones
        Zone(); //Default constructor for zone objects
};
