//
// Created by Александр on 29.11.2020.
//

#ifndef LAB4_EXPIRED_H
#define LAB4_EXPIRED_H

#include "Backup.h"

class Expired {
public:
    virtual int checkForExpiredPoints(Backup& myBackup) = 0;

    Backup& getMyBackup();
};


#endif //LAB4_EXPIRED_H
