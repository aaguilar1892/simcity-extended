#include "initialization.h"

void InitializeSim(list<Zone> &mainList, int &timeLimit, int &refreshRate){

    string configFile;
    fstream fin;
    string regionFile;
    //int timeLimit;
    //int refreshRate;

    cout << "Input Configuration File: ";
    cin >> configFile;
    cin.ignore();

    fin.open(configFile);
    if(fin.fail()){
        cout << "File error." << endl;
        exit(1);
    } //Check configuration file opens correctly

    fin.ignore(14, ':');
    getline(fin, regionFile);
    fin.ignore(11, ':');
    fin >> timeLimit;
    fin.ignore();
    fin.ignore(13, ':');
    fin >> refreshRate;
    fin.ignore(); //Get configuration data from file

    fin.close();

    fin.open(regionFile);
    if(fin.fail()){
	cout << "File error." << endl;
        exit(1);
    } //Check if region file opens correctly

    //Until file end
    int xCount = 0;
    int yCount = 0;

    char myZone;
    Zone currZone;

    while(!fin.eof()){
	    myZone = fin.get();
	    
	    if(myZone == 'R' || myZone == 'I' || myZone == 'C' || myZone == 'T' || myZone == '-' || myZone == '#' || myZone == 'P'){
	    	
		    currZone.SetZoneType(myZone);
		    currZone.Setx(xCount);
		    currZone.Sety(yCount);
		    mainList.push_back(currZone);

	    } //Assign character to represent zone type & assign x,y coords of zone, then add to the list of zones

	    if(myZone != '\n' && myZone != ',' /*&& myZone != ' '*/){
		    ++xCount;
	    }
	    if(myZone == '\n'){
		    ++yCount;
		    xCount = 0;
	    } //Increase x-coord by 1 until end of line, then reset and increase y-coord by 1
    }
}
