//
// Created by Александр on 26.10.2020.
//

#include "MagicCarpet.h"

MagicCarpet::MagicCarpet(string riderName) {
    this->speed = 10;
    this->myRiderName=riderName;
}

double MagicCarpet::getNeededDistance(double distance) {
    double res = 0;
    if (distance < 1000) {
        res = distance;
    } else {
        if (distance < 5000) {
            res = distance * 0.97;
        } else {
            if (distance < 10000) {
                res = distance * 0.9;
            } else {
                res = distance * 0.95;
            }
        }
    }
    return res;
}

string MagicCarpet::myTransportName() {
    return "MagicCarpet";
}