#ifndef encryption_h
#define encryption_h
#include "initialization.h"
#include<iostream>
#include<math.h>
#include<list>
#include<vector>
using namespace std;

void publicKey(vector<int> &encryptVals);

void encryptSim(list<Zone> &mainList, vector<int> &encryptVals);

void privateKey(list<Zone> &mainList, vector<int> &encryptVals);

#endif
