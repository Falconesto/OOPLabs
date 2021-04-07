//
// Created by Александр on 26.10.2020.
//

#include "Broom.h"

Broom::Broom(string riderName) {
    this->speed = 20;
    this->myRiderName=riderName;
}

double Broom::getNeededDistance(double distance) {
    double res = distance - int(distance / 1000) * 1000 * 0.01;
    return res;
}

string Broom::myTransportName() {
    return "Broom";
}

