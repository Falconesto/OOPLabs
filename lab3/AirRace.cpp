//
// Created by Александр on 08.11.2020.
//

#include "AirRace.h"

vector<FlyingTransport *> AirRace::runTheRace(vector<FlyingTransport *> list) {
    double minTime = DBL_MAX;
    for (auto participant : list) {
        double participantTime = participant->timeInRace(this->distance);
        if(participantTime<minTime){
            minTime = participantTime;
        }
    }
    vector<FlyingTransport *> res;
    for (auto participant : list) {
        if(participant->timeInRace(this->distance) == minTime){
            res.push_back(participant);
        }
    }
    return res;
}

AirRace::AirRace(double distance) {
    this->distance = distance;
}
