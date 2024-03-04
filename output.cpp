#include "output.h"

void printOutput(list<Zone> &mainList){
    //getting cols and rows for graph
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
    
    //cout<<row<<endl;
    //cout<<col<<endl;
    //create graph
     string graph[row+1][col+1];
    //add correct zone type to each corrdinate
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
            graph[it->Gety()][it->Getx()]= it->GetZoneType();
    }
    //print the graph

    for(int i= 0; i<= row; ++i){
        for(int j= 0; j<= col; ++j){
            if(graph[i][j] =="R" || graph[i][j] == "I" || graph[i][j] == "C" || graph[i][j] == "T" || graph[i][j] == "-" || graph[i][j] == "#" || graph[i][j] == "P" || graph[i][j] == "1" || graph [i][j] == "2" || graph[i][j] == "3"){
                cout<<graph[i][j]<<"  ";
            }
            else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
}

void printArea(list<Zone> &mainList){
    //initializing coordinatesm for area
    int xcoord1=0;
    int ycoord1=0;
    int xcoord2=0;
    int ycoord2=0;
    
   
    //get row and col
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
    //create graph
    string graph[row+1][col+1];
    //add correct zone type to each corrdinate
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
            graph[it->Gety()][it->Getx()]= it->GetZoneType();
    }
    for(int i=0; i<5; ++i){
        //cout the area for input from user
        cout<<"What rectangular area would you like printed? "<<endl;
        cout<<"Please enter the x-coordinate for top left corner of area: ";
        cin>>xcoord1;
        cout<<"Please enter the y-coordinate for top left corner of area: ";
        cin>>ycoord1;
        //cout<<endl;
        cout<<"Please enter the x-coordinate for bottom right corner of area: ";
        cin>>xcoord2;
        cout<<"Please enter the y-coordinate for bottom right corner of area: ";
        cin>>ycoord2;
        
        if(xcoord1>row || ycoord1>col || xcoord2> row|| ycoord2>col){
            cout<<"Coordinates not valid, please try again"<<endl;
        }else{
            break;
        }
    }
    
    for(int i= ycoord1; i<=ycoord2; ++i){
        for(int j=xcoord1; j<= xcoord2; ++j){
            if(graph[i][j] =="R" || graph[i][j] == "I" || graph[i][j] == "C" || graph[i][j] == "T" || graph[i][j] == "-" || graph[i][j] == "#" || graph[i][j] == "P" || graph[i][j] == "1" || graph [i][j] == "2" || graph[i][j] == "3"){
                cout<<graph[i][j]<<"  ";
            }
            else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
}

void setZone(list<Zone> &mainList, list<Zone> &resident,list<Zone> &industrial,list<Zone> &commerical){
    
    Zone currZone;
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
        if(it->GetZoneType() == 'R'){
            currZone.Setx(it->Getx());
            currZone.Sety(it->Gety());
            currZone.SetZoneType(it->GetZoneType());
            resident.push_back(currZone);
        }else if(it->GetZoneType() == 'I'){
            currZone.Setx(it->Getx());
            currZone.Sety(it->Gety());
            currZone.SetZoneType(it->GetZoneType());
            industrial.push_back(currZone);
        }else if(it->GetZoneType() == 'C'){
            currZone.Setx(it->Getx());
            currZone.Sety(it->Gety());
            currZone.SetZoneType(it->GetZoneType());
            commerical.push_back(currZone);
        }
    }
}

