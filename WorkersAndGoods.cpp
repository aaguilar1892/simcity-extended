#include "WorkersAndGoods.h"
#include <iostream>

using namespace std;

void SetWorkers(bool inc, int &workers){

    if(inc == true){
        ++workers;
    }
    if(inc == false){
        --workers;
    }
}

void SetGoods(bool inc, int &goods){

    if(inc == true){
        ++goods;
    }
    if(inc == false){
        --goods;
    }
}
