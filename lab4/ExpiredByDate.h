//
// Created by Александр on 29.11.2020.
//

#ifndef LAB4_EXPIREDBYDATE_H
#define LAB4_EXPIREDBYDATE_H

#include "Expired.h"

class ExpiredByDate : public Expired {
private:
    Time myDate;
    int expiringYear = 0;
    int expiringMonth = 1;
    int expiringDate = 0;
public:
    ExpiredByDate(Time newDate);

    int checkForExpiredPoints(Backup& myBackup) override;

    void setExpiringPeriod(int year, int month, int date);

    int getExpiringYear();

    int getExpiringMonth();

    int getExpiringDate();
};


#endif //LAB4_EXPIREDBYDATE_H
