//
// Created by Александр on 29.11.2020.
//

#include "ExpiredByMixed.h"

ExpiredByMixed::ExpiredByMixed(vector<Expired*> newLimits, bool newMinMax) {
    this->myLimits = newLimits;
    this->minMax = newMinMax;
}

int ExpiredByMixed::checkForExpiredPoints(Backup& myBackup) {
    vector<BackUpPoint> pointList = myBackup.getPointList();
    vector<BackUpPoint> tmp = myBackup.getPointList();
    vector<int> countOfExpiredPoints;
    for(int i=0; i<myLimits.size(); i++){
        int count = myLimits[i]->checkForExpiredPoints(myBackup);
        countOfExpiredPoints.push_back(count);
        myBackup.setPointList(tmp);
    }


    if (minMax) {
        int max = 0;
        int maxI = 0;
        for(int i=0; i<countOfExpiredPoints.size(); i++){
            if(countOfExpiredPoints[i] > max){
                max = countOfExpiredPoints[i];
                maxI = i;
            }
        }
        myLimits[maxI]->checkForExpiredPoints(myBackup);
        return countOfExpiredPoints[maxI];
    } else {
        int min = INT8_MAX;
        int minI = 0;
        for(int i=0; i<countOfExpiredPoints.size(); i++){
            if(countOfExpiredPoints[i] < min){
                min = countOfExpiredPoints[i];
                minI = i;
            }
        }
        myLimits[minI]->checkForExpiredPoints(myBackup);
        return countOfExpiredPoints[minI];
    }

}