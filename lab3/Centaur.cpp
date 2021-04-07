//
// Created by Александр on 26.10.2020.
//

#include "Centaur.h"

Centaur::Centaur(string riderName) {
    this->speed = 15;
    this->timeBetweenRest = 8;
    this->myRiderName=riderName;
}

double Centaur::getAddedTime(double raceTime) {
    int res = 0;
    while (raceTime > this->timeBetweenRest) {
        res += 2;
        raceTime -= this->timeBetweenRest;
    }
    return res;
}

string Centaur::myTransportName() {
    return "Centaur";
}