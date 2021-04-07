//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_FLYINGTRANSPORT_H
#define LAB3_FLYINGTRANSPORT_H

#include "Transport.h"

class FlyingTransport : public Transport {
public:
    virtual double getNeededDistance(double distance) = 0;
    double timeInRace(double distance) override;
    string myTransportType() override;
};


#endif //LAB3_FLYINGTRANSPORT_H
