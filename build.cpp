#include "build.h"

void BuildMenu(int totalPop, int &builtZones, list<Zone> &mainList){
	
	char choice;
        int xCoord, yCoord; //x & y coords of zone to develop

        //Check if population sufficient to build a new zone
	if(builtZones < (totalPop)){

                //Choose coordinates to develop and output build menu
                cout << "Choose coordinates to develop." << endl;
                cout << "x: ";
                cin >> xCoord;
		cin.ignore();
                cout << "y: ";
                cin >> yCoord;
		cin.ignore();

                //Check if chosen coordinates are valid
                bool valid;
                valid = ZoneValidity(xCoord, yCoord, mainList);

		if(valid == true){

			cout << endl;
			cout << "~~ What zone type would you like to build? ~~" << endl;
			cout << endl;

			cout << "\tR : Residential" << endl;
			cout << "\tI : Industrial" << endl;
			cout << "\tC : Commercial" << endl;
			cout << "\tP : Powerplant" << endl;
			cout << "\tT : Powerline" << endl;
			cout << "\t- : Road" << endl;
    	    cout << endl;

			cout << "Enter choice: ";
			cin >> choice;
			cin.ignore();
			cout << endl;

			Build(choice, totalPop, builtZones, mainList, xCoord, yCoord);
		}
		else{
                        cout << "ERROR: Invalid choice. Please re-enter zone type." << endl;
                        BuildMenu(totalPop, builtZones, mainList);
		}
	}
	else{
		cout << "ERROR: Insufficient population. The # of additional zones cannot exceed the total city population." << endl;
		cout << endl;
	}
}

void Build(char choice, int totalPop, int &builtZones, list<Zone> &mainList, int xCoord, int yCoord){

	char build; //Whether or not user wants to build a new zone

	//Build new city zone and set as claimed
	switch(choice){

		//Build residential
		case 'R':
			ChangeZoneType('R', xCoord, yCoord, mainList);
			++builtZones;
			break;
		//Build industrial
		case 'I':
			ChangeZoneType('I', xCoord, yCoord, mainList);
			++builtZones;
			break;
		//Build commercial
		case 'C':
			ChangeZoneType('C', xCoord, yCoord, mainList);
			++builtZones;
			break;
		//Build powerplant
		case 'P':
			ChangeZoneType('P', xCoord, yCoord, mainList);
			++builtZones;
			break;
		//Build powerline
		case 'T':
			ChangeZoneType('T', xCoord, yCoord, mainList);
			++builtZones;
			break;
		//Build road
		case '-':
			ChangeZoneType('-', xCoord, yCoord, mainList);
			++builtZones;
			break;
		//Invalid zone type
		default:
			cout << "ERROR: Invalid choice. Please re-enter zone type." << endl;
			BuildMenu(totalPop, builtZones, mainList);

			build = 'N';
			if(build = 'N'){return;} //Exit from recursive case

			break;
	}

	build = '0'; //Exit from recursive case

	cout << "Would you like to build another zone? Enter Y/N: ";
	cin >> build;
	cin.ignore();

	//If user wants to build an additional zone, call build menu again
	if(build == 'Y'){
		BuildMenu(totalPop, builtZones, mainList);
	}
}

bool ZoneValidity(int xCoord, int yCoord, list<Zone> mainList){

	bool valid = false; //If coordinates can be built on
	bool zoneFound = false; //If zone coordinates exist
	bool cityAdjacent = false; //If zone to be developed is adjacent to the city

	for(auto it : mainList){
	
		//Check if zone coordinates appear on map
		if(it.Getx() == xCoord && it.Gety() == yCoord){

			zoneFound = true; 			

			//Check if the zone has a buildable type
			if(it.GetZoneType() == 'G' || it.GetZoneType() == 'F' || it.GetZoneType() == 'D'){valid = true;}
			if(it.GetZoneType() == '~'){cout << "Cannot build on water." << endl;}
			if(it.GetZoneType() == 'M'){cout << "Cannot develop mountainous terrain." << endl;}

			//Check if zone is adjacent to city
			if(valid == true){

				for(auto iter : mainList){

					if((iter.Getx() == xCoord + 1 || iter.Getx() == xCoord || iter.Getx() == xCoord - 1) && (iter.Gety() == yCoord + 1 || iter.Gety() == yCoord || iter.Gety() == yCoord - 1)){

						if(iter.GetClaimed() == true){cityAdjacent = true;}
					}
				}
			}
		}
	}

	//Zone invalid if not adjacent to a city zone
	if(cityAdjacent == false){valid = false;}

	//Invalid zone messages
	if(zoneFound == false){cout << "Zone coordinates do not exist." << endl;}
	if(zoneFound == true && cityAdjacent == false){cout << "Zone is not adjacent to city / is already developed." << endl;}

	return valid;	
}

void ChangeZoneType(char newType, int xCoord, int yCoord, list<Zone> &mainList){

	for(auto& it : mainList){

		//Change zone type
		if(it.Getx() == xCoord && it.Gety() == yCoord){
			it.SetZoneType(newType);
			it.SetClaimed(true);
		}
	}
}
