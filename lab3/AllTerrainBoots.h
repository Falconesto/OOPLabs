//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_ALLTERRAINBOOTS_H
#define LAB3_ALLTERRAINBOOTS_H

#include "GroundTransport.h"

class AllTerrainBoots : public GroundTransport{
public:
    AllTerrainBoots(string riderName);
    double getAddedTime(double raceTime) override;
    string myTransportName() override;
};


#endif //LAB3_ALLTERRAINBOOTS_H
