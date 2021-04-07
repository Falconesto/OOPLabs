//
// Created by Александр on 29.11.2020.
//

#include "ExpiredByDate.h"

ExpiredByDate::ExpiredByDate(Time newDate) {
    this->myDate = newDate;
}

int ExpiredByDate::checkForExpiredPoints(Backup& myBackup) {
    int count = 0;
    vector<BackUpPoint> pointList = myBackup.getPointListLink();
    auto deleteTo = pointList.begin() - 1;
    for (auto i = pointList.begin(); i != pointList.end(); i++) {
        Time expiringTime(i->getDateOfCreation().getExpiringDate(expiringYear, expiringMonth, expiringDate));
        if (expiringTime > myDate) {
            break;
        } else {
            deleteTo = i;
            count++;
        }
    }
    if (deleteTo != pointList.begin() - 1) {
        auto newDeleteTo = deleteTo + 1;
        if (newDeleteTo == pointList.end()) {
            pointList.erase(pointList.begin(), newDeleteTo);
            myBackup.setPointList(pointList);
            return count;
        }
        for (newDeleteTo; newDeleteTo != pointList.end(); newDeleteTo++) {
            if (newDeleteTo->getReal()) {
                break;
            } else {
                count++;
            }
        }
        if (newDeleteTo == pointList.end()) {
            throw (string) "I can not delete expired point because the next ones are only incremented";
        } else {
            pointList.erase(pointList.begin(), newDeleteTo);
        }
    }
    myBackup.setPointList(pointList);
    return count;
}

int ExpiredByDate::getExpiringYear() {
    return this->expiringYear;
}

int ExpiredByDate::getExpiringMonth() {
    return this->expiringMonth;
}

int ExpiredByDate::getExpiringDate() {
    return this->expiringDate;
}

void ExpiredByDate::setExpiringPeriod(int year, int month, int date) {
    this->expiringYear = year;
    this->expiringMonth = month;
    this->expiringDate = date;
}