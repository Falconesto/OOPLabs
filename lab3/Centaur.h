//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_CENTAUR_H
#define LAB3_CENTAUR_H

#include "GroundTransport.h"

class Centaur : public GroundTransport{
public:
    Centaur(string riderName);
    double getAddedTime(double raceTime) override;
    string myTransportName() override;
};


#endif //LAB3_CENTAUR_H
