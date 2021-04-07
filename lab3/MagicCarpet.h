//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_MAGICCARPET_H
#define LAB3_MAGICCARPET_H

#include "FlyingTransport.h"

class MagicCarpet : public FlyingTransport {
public:
    MagicCarpet(string riderName);
    double getNeededDistance(double distance) override;
    string myTransportName() override;
};


#endif //LAB3_MAGICCARPET_H
