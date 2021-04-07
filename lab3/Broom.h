//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_BROOM_H
#define LAB3_BROOM_H

#include "FlyingTransport.h"

class Broom : public FlyingTransport{
public:
    Broom(string riderName);
    double getNeededDistance(double distance) override;
    string myTransportName() override;
};


#endif //LAB3_BROOM_H
