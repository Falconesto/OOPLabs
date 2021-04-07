//
// Created by Александр on 26.10.2020.
//

#include "GroundTransport.h"

double GroundTransport::timeInRace(double distance) {
    double raceTime = distance / this->speed;
    return (raceTime + this->getAddedTime(raceTime));
}

string GroundTransport::myTransportType(){
    return "ground";
}