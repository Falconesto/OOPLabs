//
// Created by Александр on 08.11.2020.
//

#ifndef LAB3_AIRRACE_H
#define LAB3_AIRRACE_H

#include "Race.h"

class AirRace : public Race {
public:
    AirRace(double distance);
    vector<FlyingTransport*> runTheRace(vector<FlyingTransport*> list);
};


#endif //LAB3_AIRRACE_H
