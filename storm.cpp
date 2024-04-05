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
    
    cout<<"random number: ";
    cout<<random<<endl;
    
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
    int xcoord;
    int ycoord;
    xcoord = rand() % row + 1;
    ycoord = rand() % col +1;
    
    cout<<"xcoord= "<<xcoord<<endl;
    cout<<"ycoord= "<<ycoord<<endl;
    
}
