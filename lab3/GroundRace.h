//
// Created by Александр on 08.11.2020.
//

#ifndef LAB3_GROUNDRACE_H
#define LAB3_GROUNDRACE_H

#include "Race.h"

class GroundRace : public Race {
public:
    GroundRace(double distance);
    vector<GroundTransport*> runTheRace(vector<GroundTransport*> list);
};


#endif //LAB3_GROUNDRACE_H
