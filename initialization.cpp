#include "initialization.h"

void InitializeSim(list<Zone> &mainList, int &timeLimit, int &refreshRate){

    string configFile;
    fstream fin;
    string regionFile;

    //Get configuration file name from user
    cout << "Input Configuration File: ";
    cin >> configFile;
    cin.ignore();

    //Check configuration file opens correctly
    fin.open(configFile);
    if(fin.fail()){
        cout << "File error." << endl;
        exit(1);
    } 

    //Get configuration data from file
    fin.ignore(14, ':');
    getline(fin, regionFile);
    fin.ignore(11, ':');
    fin >> timeLimit;
    fin.ignore();
    fin.ignore(13, ':');
    fin >> refreshRate;
    fin.ignore(); 

    fin.close();

    //Check if region file opens correctly
    fin.open(regionFile);
    if(fin.fail()){
    cout << "File error." << endl;
        exit(1);
    } 

    int xCount = 0;
    int yCount = 0; //Variables representing x & y coordinates
    int pop= 0;

    char myZone; //Character representing the zone type
    Zone currZone;

    while(!fin.eof()){
        //Assign character for zone type
        myZone = fin.get();
        
        if(myZone == 'R' || myZone == 'I' || myZone == 'C' || myZone == 'T' || myZone == '-' || myZone == '#' || myZone == 'P'){
            
            currZone.SetZoneType(myZone);
            //currZone.setPollutionLevel(0); //Set pollution level to 0

            //Assign x & y coordinates of zone
            currZone.Setx(xCount);
            currZone.Sety(yCount);
            currZone.SetPop(pop);

            //Add zone to the list of zones, mainList
            mainList.push_back(currZone);
        }

        //Increase x-coordinate by 1 until end of line, then reset and increase y-coordinate by 1
        if(myZone != '\n' && myZone != ','){
            ++xCount;
        }
        if(myZone == '\n'){
            ++yCount;
            xCount = 0;
        }
    }
}
