//
// Created by Александр on 29.11.2020.
//

#ifndef LAB4_EXPIREDBYSIZE_H
#define LAB4_EXPIREDBYSIZE_H

#include "Expired.h"

class ExpiredBySize : public Expired {
private:
    int size;
public:
    ExpiredBySize(int newSize);

    int checkForExpiredPoints(Backup& myBackup) override;
};


#endif //LAB4_EXPIREDBYSIZE_H
