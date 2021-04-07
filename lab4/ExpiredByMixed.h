//
// Created by Александр on 29.11.2020.
//

#ifndef LAB4_EXPIREDBYMIXED_H
#define LAB4_EXPIREDBYMIXED_H

#include "Expired.h"

class ExpiredByMixed : Expired {
private:
    vector<Expired*> myLimits;
    bool minMax;
public:
    ExpiredByMixed(vector<Expired*> newLimits, bool newMinMax);

    int checkForExpiredPoints(Backup& myBackup) override;
};


#endif //LAB4_EXPIREDBYMIXED_H
