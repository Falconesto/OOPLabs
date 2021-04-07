//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_MORTAR_H
#define LAB3_MORTAR_H

#include "FlyingTransport.h"

class Mortar : public FlyingTransport{
public:
    Mortar(string riderName);
    double getNeededDistance(double distance) override;
    string myTransportName() override;
};


#endif //LAB3_MORTAR_H
