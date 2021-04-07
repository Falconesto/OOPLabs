//
// Created by Александр on 26.10.2020.
//

#include "SpeedCamel.h"

SpeedCamel::SpeedCamel(string riderName){
    this->speed=40;
    this->timeBetweenRest=10;
    this->myRiderName=riderName;
}

double SpeedCamel::getAddedTime(double raceTime) {
    int res = 0;
    if (raceTime > this->timeBetweenRest) {
        res += 5;
        raceTime -= this->timeBetweenRest;
        if(raceTime > this->timeBetweenRest*2) {
            res += 6.5;
            raceTime -= this->timeBetweenRest;
            while (raceTime > this->timeBetweenRest) {
                res += 8;
                raceTime -= this->timeBetweenRest;
            }
        }
    }
    return res;
}

string SpeedCamel::myTransportName() {
    return "SpeedCamel";
}