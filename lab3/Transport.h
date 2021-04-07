//
// Created by Александр on 26.10.2020.
//

#ifndef LAB3_TRANSPORT_H
#define LAB3_TRANSPORT_H

#include "string"
using namespace std;


class Transport {
protected:
    int speed;
    string myRiderName;
public:
    string getMyRiderName();
    virtual double timeInRace(double distance) = 0;
    virtual string myTransportName() = 0;
    virtual string myTransportType() = 0;
};


#endif //LAB3_TRANSPORT_H
