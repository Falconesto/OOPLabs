//
// Created by Александр on 26.10.2020.
//

#include "Mortar.h"

Mortar::Mortar(string riderName) {
    this->speed = 8;
    this->myRiderName=riderName;
}

double Mortar::getNeededDistance(double distance) {
    double res = distance * 0.94;
    return res;
}

string Mortar::myTransportName() {
    return "Mortar";
}