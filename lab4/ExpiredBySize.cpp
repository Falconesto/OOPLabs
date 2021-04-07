//
// Created by Александр on 29.11.2020.
//

#include "ExpiredBySize.h"

ExpiredBySize::ExpiredBySize(int newSize) {
    this->size = newSize;
}

int ExpiredBySize::checkForExpiredPoints(Backup& myBackup) {
    int count = 0;
    int sizeSum = myBackup.getSumOfSizesOfPoints();
    vector<BackUpPoint> pointList = myBackup.getPointListLink();
    if (sizeSum > size) {
        auto deleteTo = pointList.begin();
        for (deleteTo; deleteTo != pointList.end(); deleteTo++) {
            sizeSum -= deleteTo->getSizeOfPoint();
            count++;
            if (sizeSum <= size) {
                break;
            }
        }
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
