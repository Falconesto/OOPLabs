//
// Created by Александр on 26.10.2020.
//

#include "BactrianCamel.h"

BactrianCamel::BactrianCamel(string riderName) {
    this->speed = 10;
    this->timeBetweenRest = 30;
    this->myRiderName=riderName;
}

double BactrianCamel::getAddedTime(double raceTime) {
    int res = 0;
    if (raceTime > this->timeBetweenRest) {
        res += 5;
        raceTime -= this->timeBetweenRest;
        while (raceTime > this->timeBetweenRest) {
            res += 8;
            raceTime -= this->timeBetweenRest;
        }
    }
    return res;
}

string BactrianCamel::myTransportName() {
    return "BactrianCamel";
}