//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_BACTRIANCAMEL_H
#define LAB3_BACTRIANCAMEL_H

#include "GroundTransport.h"

class BactrianCamel : public GroundTransport {
public:
    BactrianCamel(string riderName);
    double getAddedTime(double raceTime) override;
    string myTransportName() override;
};


#endif //LAB3_BACTRIANCAMEL_H
