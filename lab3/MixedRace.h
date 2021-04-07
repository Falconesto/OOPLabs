//
// Created by Александр on 08.11.2020.
//

#ifndef LAB3_MIXEDRACE_H
#define LAB3_MIXEDRACE_H

#include "Race.h"

class MixedRace : public Race {
public:
    MixedRace(double distance);
    vector<Transport*> runTheRace(vector<Transport*> list);
};


#endif //LAB3_MIXEDRACE_H
