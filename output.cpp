#include "output.h"

void printOutput(list<Zone> &mainList){
    //get max row and col
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
        vector<vector<string>> graph(row+1, vector<string>(col+1));
       
       //get zonetype, if pop in that zone type is above zero then convert pop to string and put in graph in place of zone type
        for(auto it = mainList.begin(); it != mainList.end(); ++it){
            if(it->GetZoneType() == 'R'|| it->GetZoneType() == 'I' || it->GetZoneType() == 'C'){
                if(it->GetPop() > 0){
                    graph[it->Gety()][it->Getx()]= to_string(it->GetPop());
                }else{
                    graph[it->Gety()][it->Getx()]= it->GetZoneType();
                }}else{
                    graph[it->Gety()][it->Getx()]= it->GetZoneType();
                }
        }
       //print the graph
       for(int i= 0; i<= row; ++i){
           for(int j= 0; j<= col; ++j){
               if(graph[i][j] =="R" || graph[i][j] == "I" || graph[i][j] == "C" || graph[i][j] == "T" || graph[i][j] == "-" || graph[i][j] == "#" || graph[i][j] == "P" || graph[i][j] == "1" || graph [i][j] == "2" || graph[i][j] == "3" || graph[i][j] == "4" || graph[i][j] == "5" || graph[i][j] == "6" || graph[i][j] == "8" || graph[i][j] == "9" || graph[i][j] == "10"){
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
    
  //ask user for coords
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
    
    //create graph
    string graph[row+1][col+1];
    
    //get zonetype, if pop in that zone type is above zero then convert pop to string and put in graph in place of zone type
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
        if(it->GetZoneType() == 'R'|| it->GetZoneType() == 'I' || it->GetZoneType() == 'C'){
            if(it->GetPop() > 0){
                graph[it->Gety()][it->Getx()]= to_string(it->GetPop());
            }else{
                graph[it->Gety()][it->Getx()]= it->GetZoneType();
            }}else{
            graph[it->Gety()][it->Getx()]= it->GetZoneType();
            }
    }
    
    //print graph
    for(int i= ycoord1; i<=ycoord2; ++i){
        for(int j=xcoord1; j<= xcoord2; ++j){
            if(graph[i][j] =="R" || graph[i][j] == "I" || graph[i][j] == "C" || graph[i][j] == "T" || graph[i][j] == "-" || graph[i][j] == "#" || graph[i][j] == "P" || graph[i][j] == "1" || graph [i][j] == "2" || graph[i][j] == "3" || graph[i][j] == "4"|| graph[i][j] == "5" || graph[i][j] == "6" || graph[i][j] == "8" || graph[i][j] == "9" || graph[i][j] == "10"){
                cout<<graph[i][j]<<"  ";
            }
            else{
                cout<<"   ";
            }
        }
        cout<<endl;
    }
    
    //initalize the pops and the bounds
    int resPop=0;
    int comPop=0;
    int indPop=0;
    int x=0;
    int y=0;
            
    //get pops inside of bounds from the main list and add to pops for later output
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
        x= it->Getx();
        y= it->Gety();
        
        if(x >= xcoord1 && x <= xcoord2 && y >= ycoord1 && y <= ycoord2){
            if(it->GetZoneType() == 'R'&& it->GetPop()> 0){
                resPop=resPop+it->GetPop();
            }else if(it->GetZoneType() == 'C'&& it->GetPop()> 0){
                comPop=comPop + it->GetPop();
            }else if(it->GetZoneType() == 'I'&& it->GetPop()> 0){
                indPop=indPop + it->GetPop();
            }else{}
        }
    }
    
    //print pops
    cout<<"Populations for specific area:"<<endl;
    cout<<"Residental Zone: "<<resPop<<endl;
    cout<<"Industrial Zone: "<<indPop<<endl;
    cout<<"Commercial Zone: "<<comPop<<endl;
    
}

void printPop(list<Zone> &mainList){
    //initalize pops
    int resPop=0;
    int comPop=0;
    int indPop=0;
    
    //get pops for each zone type to add up by iterating through mainlist
    for(auto it = mainList.begin(); it != mainList.end(); ++it){
        if(it->GetZoneType() == 'R'&& it->GetPop()> 0){
            resPop=resPop+it->GetPop();
        }else if(it->GetZoneType() == 'C'&& it->GetPop()> 0){
            comPop=comPop + it->GetPop();
        }else if(it->GetZoneType() == 'I'&& it->GetPop()> 0){
            indPop=indPop + it->GetPop();
        }else{}
    }
       
    //print pops
    cout<<"Populations for specific area:"<<endl;
    cout<<"Residental Zone: "<<resPop<<endl;
    cout<<"Industrial Zone: "<<indPop<<endl;
    cout<<"Commercial Zone: "<<comPop<<endl;
}

/*void printPollution(list<Zone>& mainList) {
    int row = 0;
    int col = 0;
    cout << "Final Regional Pollution State:" << endl;
    // Assuming you have a similar setup for rows and columns as in printOutput
    for(int i = 0; i <= row; ++i) {
        for(int j = 0; j <= col; ++j) {
            auto it = find_if(mainList.begin(), mainList.end(), [i, j](Zone& zone) {
                return zone.Getx() == j && zone.Gety() == i;
            });
            if (it != mainList.end()) {
                cout << it->getPollutionLevel() << " ";
            } else {
                cout << "0 "; // Assuming zero pollution for non-industrial zones or empty spaces
            }
        }
        cout << endl;
    }
}*/

// output.cpp 
void printPollution(list<Zone> &mainList) {
    //get max row and col
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

    // Create a pollution map
    int pollutionMap[row+1][col+1]; 

    // Initialize pollution map with 0
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            pollutionMap[i][j] = 0;
        }
    }  

    // Update pollution map based on zone pollution levels
    for (auto it = mainList.begin(); it != mainList.end(); ++it) {
        pollutionMap[it->Gety()][it->Getx()] = it->getPollutionLevel();
    }

    // Print the Pollution Map
    cout << "Pollution Map:" << endl;
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            if (pollutionMap[i][j] == 0) {
                cout << "  "; // Representation for no pollution
            } else {
                cout << pollutionMap[i][j] << " "; 
            }
        }
        cout << endl;
    }
}