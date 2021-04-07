//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_SPEEDCAMEL_H
#define LAB3_SPEEDCAMEL_H

#include "GroundTransport.h"

class SpeedCamel : public GroundTransport {
public:
    SpeedCamel(string riderName);
    double getAddedTime(double raceTime) override;
    string myTransportName() override;
};


#endif //LAB3_SPEEDCAMEL_H
