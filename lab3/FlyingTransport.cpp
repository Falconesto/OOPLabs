//
// Created by Александр on 26.10.2020.
//

#include "FlyingTransport.h"

double FlyingTransport::timeInRace(double distance) {
    double time = this->getNeededDistance(distance) / this->speed;
    return time;
}

string FlyingTransport::myTransportType(){
    return "air";
}