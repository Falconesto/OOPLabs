//
// Created by Александр on 08.11.2020.
//

#include "GroundRace.h"

vector<GroundTransport *> GroundRace::runTheRace(vector<GroundTransport *> list) {
    double minTime = DBL_MAX;
    for (auto participant : list) {
        double participantTime = participant->timeInRace(this->distance);
        if(participantTime<minTime){
            minTime = participantTime;
        }
    }
    vector<GroundTransport *> res;
    for (auto participant : list) {
        if(participant->timeInRace(this->distance) == minTime){
            res.push_back(participant);
        }
    }
    return res;
}

GroundRace::GroundRace(double distance) {
    this->distance = distance;
}
