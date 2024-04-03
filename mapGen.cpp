#include "mapGen.h"

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
}
