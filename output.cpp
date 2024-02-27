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
    char graph[row+1][col+1];
    //add correct zone type to each corrdinate
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
            graph[it->Gety()][it->Getx()]= it->GetZoneType();
    }
    //print the graph
    for(int i= 0; i<= row; ++i){
        for(int j= 0; j<= col; ++j){
            if(graph[i][j] =='R' || graph[i][j] == 'I' || graph[i][j] == 'C' || graph[i][j] == 'T' || graph[i][j] == '-' || graph[i][j] == '#' || graph[i][j] == 'P'){
                cout<<graph[i][j]<<"  ";
            }
            else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
}
