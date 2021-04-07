//
// Created by Александр on 29.11.2020.
//

#include "ExpiredByNumber.h"

ExpiredByNumber::ExpiredByNumber(int newNumber) {
    this->number = newNumber;
}

int ExpiredByNumber::checkForExpiredPoints(Backup& myBackup) {
    int count = 0;
    vector<BackUpPoint> pointList = myBackup.getPointListLink();
    if (pointList.size() > number) {
        count = pointList.size() - number;
        auto deleteTo = pointList.end() - number;
        auto newDeleteTo = deleteTo;
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