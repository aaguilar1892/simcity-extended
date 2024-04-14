#include "encryption.h"

//create encyption key using RSA
void publicKey(vector<int> &encryptVals){
    int userval; 
    int loop = 1; 
    int n; 
    int phi; 
    int e;//variables for creating the public key
    
    //only need two values so it loops twice
    while(loop != 3){
        
        //enter a value greater than zero for algorithm and modulo
        cout << "Please enter a prime integer value that is greater than 1." << endl; 
        cout << "Please Enter Value: ";
        cin >> userval;
        
        if(userval > 0){
            encryptVals.push_back(userval);
            loop = loop + 1;
        } else {
            cout << "Value is not valid. Please enter a valid value." << endl;
        }
    
    }
    //create n which is the second part of the encryption key
    n = encryptVals[0] * encryptVals[1];
    encryptVals.push_back(n);
    
    //helps find phi which is used to find the first part of the encryption key and decryption key
    phi = (encryptVals[0] - 1) * (encryptVals[1] - 1); 
    encryptVals.push_back(phi);

    //checking for coprime numbers
    for(int i = 2; i < n; i++){
        
        if(i % 2 != 0){
            
            if(phi % i != 0){

                if(n % i != 0){

                    e = i;
                    break;

                }

            }

        }
        
    }
    encryptVals.push_back(e);

    cout << "Public Key: (" << encryptVals[4] << ", " << encryptVals[2] << ") " << endl;

}

void encryptSim(list<Zone> &mainList, vector<int> &encryptVals){
    //encryption characters
    vector<char> encryptOpts = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '-', '+', '#', '!', '?', '|', '~', ' '};
    int addedAlphVal;
    int finalProd;
    int power = encryptVals[0];
    int encryptPop; //encryption values;

    for(int i = 1; i <= encryptVals[4]; i++) {
        power = power * encryptVals[0];
    }

    finalProd = power % encryptVals[1];

    for(auto& iter: mainList) {
        int encryptVal = 0;
        char encryptChar;

        //Looking at the zone type
        if (iter.GetZoneType() == 'C'){
            encryptVal = finalProd + 2;
        } else if(iter.GetZoneType() == 'D') {
            encryptVal = finalProd + 3;
        } else if (iter.GetZoneType() == 'F') {
            encryptVal = finalProd + 5;
        } else if (iter.GetZoneType() == 'G') {
            encryptVal = finalProd + 6;
        } else if (iter.GetZoneType() == 'I') {
            encryptVal = finalProd + 8;
        } else if(iter.GetZoneType() == 'M') {
            encryptVal = finalProd + 12;
        } else if (iter.GetZoneType() == 'R') {
            encryptVal = finalProd + 17;
        } else if (iter.GetZoneType() == 'T') {
            encryptVal = finalProd + 19;
        } else if (iter.GetZoneType() == '-') {
            encryptVal = finalProd + 26;
        } else if (iter.GetZoneType() == '#') {
            encryptVal = finalProd + 28;
        } else if (iter.GetZoneType() == '|'){
            encryptVal = finalProd + 31;
        } else if (iter.GetZoneType() == '~'){
            encryptVal = finalProd + 32;
        } else if (iter.GetZoneType() == ' '){
            encryptVal = finalProd + 33;
        }

        //34 options for encryption, narrowing down the modulo for RSA algorithm      
        if(encryptVal >= 34) {
            encryptVal = encryptVal % 34;
        }

        //Gets and sets the new encrypted character
        encryptChar = encryptOpts[encryptVal];
        iter.SetZoneType(encryptChar);

        //Get new encrypted population
        
        if(iter.GetPop() == 1){
            encryptPop = finalProd + 1;
        } else if(iter.GetPop() == 2) {
            encryptPop = finalProd + 2;
        } else if (iter.GetPop() == 3){
            encryptPop = finalProd + 3;
        } else if (iter.GetPop() == 4) {
            encryptPop = finalProd + 4;
        }

        iter.SetPop(encryptPop);
        
    }
}

void privateKey(list<Zone> &mainList, vector<int> &encryptVals){
    int dec = 1;
    int num = 1;
    int e = encryptVals[4];
    int phi = encryptVals[3];
    int loop = 1;

    while(loop != 3){
        dec = num * encryptVals[4];
        //doing the first one if it is a smaller number is too easy to decrypt
        if(dec % phi != 1){
            num++;
        } else {
            loop++;
            num++;            
        }

    }

    dec = dec / encryptVals[4];
    encryptVals.push_back(dec);

    //print private key value
    cout << "Private Key: (" << encryptVals[5] << ", " << encryptVals[2] << ") " << endl;

}
