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

        bool prevChanged; //Variable for whether or not the zone was changed during the current time step
        int pollutionLevel; //Variable for the pollution level of the zone

    public:

        void Setx(int xCoord);
        void Sety(int yCoord);
        void SetZoneType(char type); //Sets for zone coordinates and type
        void SetPop(int pop); //Set zone population
        void SetPrevChanged(bool change); //Set zone to changed or unchanged

        int CalcWorkers(list<Zone> mainList, int workers); //Calculate total # available workers

        int Getx();
        int Gety();
        char GetZoneType(); //Gets for zone coordinates and type
        int GetPop(); //Get zone population
        int GetWorkers();
        int GetGoods(); //Gets for # available workers and goods in a zone
        

        void CheckAdjZonesC(int &workers, int &goods, int &changed, list<Zone> &mainList); //Analyze commercial zones
        void CheckAdjZonesR(int &workers, int &goods, int &changed, list<Zone> &mainList); //Analyze residential zones
        void CheckAdjZonesI(int &workers, int &goods, int &changed, list<Zone> &mainList); //Analyze industrial zones
        Zone(); //Default constructor for zone objects

        void setPollutionLevel(int level); //Set pollution level of zone
        int getPollutionLevel(); //Get pollution level of zone
        void spreadPollution(list<Zone> &mainList); //Spread pollution to adjacent zones
};
