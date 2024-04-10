#include "initialization.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

bool storm(list<Zone> &mainList){
    //random number
    int random;
    //setting severe weather
    bool severeweather= false;
    
    random = rand() % 10 + 1;
    
    //cout<<"random number: ";
    // cout<<random<<endl;

   cout<<"Weather: ";
    
    switch(random){
        case 1:
            //severe weather
            cout<<"Severe Tornado"<<endl;
            severeweather= true;
            break;
        case 2:
            //weather but it is not severe
            cout<<"Normal Storm"<<endl;
            break;
        case 3:
            //no storm
            cout<<"Sunshine"<<endl;
            break;
        case 4:
            //severe weather
            cout<<"Severe Weather"<<endl;
            severeweather= true;
            break;
        case 5:
            //no storm
            cout<<"Sun and Light wind"<<endl;
            break;
        case 6:
            //severe weather
            cout<<"Acid Rain"<<endl;
            severeweather= true;
            break;
        case 7:
            //not severe
            cout<<"Light showers"<<endl;
            break;
        case 8:
            //no storm
            cout<<"Sunshine"<<endl;
            break;
        case 9:
            //no storm
            cout<<"Overcast"<<endl;
            break;
        case 10:
            //severe weather
            cout<<"Severe Sinkhole"<<endl;
            severeweather = true;
            break;
    }
    
    return severeweather;
}

void severe(list<Zone> &mainList){
    //getting max row and col of simcity for storm location
    int row=0;
    int col=0;
    for( auto it : mainList){
        if(it.Getx() > col){
            col= it.Getx();
        }
        if(it.Gety() > row){
            row= it.Gety();
        }
    }

    //getting random coordinates
    int xcoord;
    int ycoord;
    xcoord = rand() % row + 1;
    ycoord = rand() % col +1;
    
    //cout storm location
    cout<<"storm coordinates: ("<<xcoord<<", "<<ycoord<<")"<<endl;

    //practice to make sure its working/debug
    //int pop=0;
    //int newpop=0;

    //iterates through the mainlist to find the correct corridnate then it is resident/commerical/or industrial area it changes pop
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
       int x= it->Getx();
       int y= it->Gety();
        
        if(x == xcoord && y == ycoord){
            //cout<<"location thing: "<< it->GetZoneType()<<endl;
            if(it->GetZoneType() == 'R'&& it->GetPop()> 0){
                //pop=it->GetPop();
                it->SetPop(0);
                //newpop=it->GetPop();
            }else if(it->GetZoneType() == 'C'&& it->GetPop()> 0){
                //pop=it->GetPop();
                it->SetPop(0);
                //newpop=it->GetPop();
            }else if(it->GetZoneType() == 'I'&& it->GetPop()> 0){
                //pop=it->GetPop();
                it->SetPop(0);
                //newpop=it->GetPop();
            }else{}
        }
    }
}
