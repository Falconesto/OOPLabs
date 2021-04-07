//
// Created by Александр on 08.11.2020.
//

#include "MixedRace.h"

vector<Transport *> MixedRace::runTheRace(vector<Transport *> list) {
    double minTime = DBL_MAX;
    for (auto participant : list) {
        double participantTime = participant->timeInRace(this->distance);
        if(participantTime<minTime){
            minTime = participantTime;
        }
    }
    vector<Transport *> res;
    for (auto participant : list) {
        if(participant->timeInRace(this->distance) == minTime){
            res.push_back(participant);
        }
    }
    return res;
}

MixedRace::MixedRace(double distance) {
    this->distance = distance;
}
