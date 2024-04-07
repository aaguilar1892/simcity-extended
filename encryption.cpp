#include "encryption.h"

//create encyption key using RSA
void publicKey(vector<int> &encryptVals){
    int userval;
    int loop = 1;
    
    //only need two values so it loops twice
    while(loop != 3){
        
        //enter a value greater than zero for algorithm and modulo
        cout << "Please enter an integer value that is greater than 0." << endl; 
        cout << "Please Enter Value: " << endl;
        cin >> userval;
        
        if(userval > 0){
            encryptVals.push_back(userval);
            loop = loop + 1;
        } else {
            cout << "Value is not valid. Please enter a valid value." << endl;
        }
    
    }
}

/*void encryptSim(list<Zone> &mainList, vector<int> encryptVals){
    //encryption characters
    //vector<char> encryptOpts = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '-', '+', '#', '!', '?'};
    
    int addedVal;
    int currVal;

    //31 options for encryption, narrowing down the modulo for RSA algorithm
    if(encryptVals[1] >= 30){
        int newVal;
        newVal = encryptVals[1] % 30;
        //value for modulo cannot be 0 or RSA algorithm will become undefined
        if(newVal == 0){
            newVal = 1;
        }
            encryptVals.push_back(newVal);
            addedVal = (pow(2, encryptVals[0])) % encryptVals[2];
    } else {
        addedVal = (pow(2, encryptVals[0])) % encryptVals[1];
    }
    
    for(auto iter: mainList) {
        
        if (iter.GetZoneType() == 'C'){
            currVal = 2;
        } else if (iter. GetZoneType() == 'I') {
            currVal = 8;
        } else if (iter.GetZoneType() == 'T') {
            currVal = 19;
        }

    }
}
*/
