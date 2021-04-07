//
// Created by Александр on 26.10.2020.
//

#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots(string riderName) {
    this->speed = 6;
    this->timeBetweenRest = 60;
    this->myRiderName = riderName;
}

double AllTerrainBoots::getAddedTime(double raceTime) {
    int res = 0;
    if (raceTime > this->timeBetweenRest) {
        res += 10;
        raceTime -= this->timeBetweenRest;
        while (raceTime > this->timeBetweenRest) {
            res += 5;
            raceTime -= this->timeBetweenRest;
        }
    }
    return res;
}

string AllTerrainBoots::myTransportName() {
    return "AllTerrainBoots";
}
