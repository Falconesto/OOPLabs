//
// Created by Александр on 29.11.2020.
//

#ifndef LAB4_EXPIREDBYNUMBER_H
#define LAB4_EXPIREDBYNUMBER_H

#include "Expired.h"

class ExpiredByNumber : public Expired {
private:
    int number;
public:
    ExpiredByNumber(int newNumber);

    int checkForExpiredPoints(Backup& myBackup) override;
};


#endif //LAB4_EXPIREDBYNUMBER_H
