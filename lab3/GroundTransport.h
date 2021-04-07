//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_GROUNDTRANSPORT_H
#define LAB3_GROUNDTRANSPORT_H

#include "Transport.h"

class GroundTransport : public Transport {
protected:
    int timeBetweenRest;
public:
    virtual double getAddedTime(double raceTime) = 0;
    double timeInRace(double distance) override;
    string myTransportType() override;
};


#endif //LAB3_GROUNDTRANSPORT_H
