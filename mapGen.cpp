#include "mapGen.h"

void EnvironmentGen(list<Zone> &mainList){

	srand(time(NULL)); //Initialize random number generator

	//Generate water
	for(auto& it : mainList){
				
		if(rand() % 78 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){
			it.SetZoneType('~');
		}
	}
	
	for(auto& it : mainList){

		for(auto& iter : mainList){

			if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() == it.Getx() - 1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() == it.Gety() - 1) && (!(iter.Getx() == it.Getx() && iter.Gety() == it.Gety()))){
				
				if(iter.GetZoneType() == '~'){
					if(rand() % 3 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){it.SetZoneType('~');}
				}
			}
		}
	}

	//Fill in single zone islands
	int numWater = 0;
	for(auto& it : mainList){

		for(auto& iter : mainList){

                        if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() == it.Getx() - 1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() == it.Gety() - 1) && (!(iter.Getx() == it.Getx() && iter.Gety() == it.Gety()))){

				if(iter.GetZoneType() == '~'){
					++numWater;
				}
			}
		}
		
		if(numWater > 4){it.SetZoneType('~');}
		numWater = 0;
	}

	//Generate mountains
        for(auto& it : mainList){

                if(rand() % 50 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){
                        it.SetZoneType('M');
                }
        }

        for(auto& it : mainList){

                for(auto& iter : mainList){

                        if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() == it.Getx() - 1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() == it.Gety() - 1) && (!(iter.Getx() == it.Getx() && iter.Gety() == it.Gety()))){

                                if(iter.GetZoneType() == 'M'){
                                        if(rand() % 4 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){it.SetZoneType('M');}
                                }
                        }
                }
        }

	//Generate forests
        for(auto& it : mainList){

                if(rand() % 25 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){
                        it.SetZoneType('F');
                }
        }

        for(auto& it : mainList){

                for(auto& iter : mainList){

                        if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() == it.Getx() - 1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() == it.Gety() - 1) && (!(iter.Getx() == it.Getx() && iter.Gety() == it.Gety()))){

                                if(iter.GetZoneType() == 'F'){
                                        if(rand() % 3 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){it.SetZoneType('F');}
                                }
                        }
                }
        }

	//Generate deserts
        for(auto& it : mainList){

                if(rand() % 20 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){
                        it.SetZoneType('D');
                }
        }

        for(auto& it : mainList){

                for(auto& iter : mainList){

                        if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() == it.Getx() - 1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() == it.Gety() - 1) && (!(iter.Getx() == it.Getx() && iter.Gety() == it.Gety()))){

                                if(iter.GetZoneType() == 'D'){
                                        if(rand() % 3 == 0 && it.GetClaimed() != true && it.GetZoneType() == 'X'){it.SetZoneType('D');}
                                }
                        }
                }
        }

        //Fill in single zones surrounded by desert
        int numDesert = 0;
        for(auto& it : mainList){

                for(auto& iter : mainList){

                        if((iter.Getx() == it.Getx() || iter.Getx() == it.Getx() + 1 || iter.Getx() == it.Getx() - 1) && (iter.Gety() == it.Gety() || iter.Gety() == it.Gety() + 1 || iter.Gety() == it.Gety() - 1) && (!(iter.Getx() == it.Getx() && iter.Gety() == it.Gety()))){

                                if(iter.GetZoneType() == 'D'){
                                        ++numDesert;
                                }
                        }
                }

                if(numDesert > 4){it.SetZoneType('D');}
                numDesert = 0;
        }

	//Generate grasslands
	for(auto& it : mainList){
		if(it.GetZoneType() == 'X'){it.SetZoneType('G');}
	}
}

void InitializeMap(list<Zone> &mainList, int &xmax, int &ymax){

        Zone currZone;
        bool match = false;

        //Shift all city zones down and right by 10
        for(auto& it : mainList){
                it.Setx(it.Getx() + 10);
                it.Sety(it.Gety() + 10);
        }

        for(int j = 0; j < ymax + 20; ++j){

                for(int i = 0; i < xmax + 20; ++i){

                        //Create new environment zone
                        currZone.Setx(i);
                        currZone.Sety(j);
                        currZone.SetPop(0);
                        currZone.SetZoneType('X');
                        currZone.SetClaimed(false);

                        //Check if current coordinates are occupied by a city zone
                        for(auto it : mainList){

                                if(it.Getx() == currZone.Getx() && it.Gety() == currZone.Gety()){
                                        match = true;
                                }
                        }

                        //Add new environment zone to list if current coordinates are empty
                        if(match == false){
                                mainList.push_back(currZone);
                        }

                        //Reset to no matches
                        match = false;
                }
        }

	EnvironmentGen(mainList);
}
