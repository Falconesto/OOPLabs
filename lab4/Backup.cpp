//
// Created by Александр on 15.11.2020.
//

#include "Backup.h"

Backup::Backup() {
    separated = true;
    pointList = {};
}

Backup::Backup(vector<File> newFiles, Time myDate, bool separated) {
    this->separated = separated;
    BackUpPoint newBackup(newFiles, myDate, separated);
    pointList.push_back(newBackup);
}

void Backup::addNewBackUpPoint(vector<File> newFiles, Time myDate, bool real) {
    BackUpPoint newBackup(newFiles, myDate, real, this->pointList.back(), separated);
    pointList.push_back(newBackup);
}

int Backup::getNumberOfFilesInLastBackUpPoint() {
    return pointList.back().getNumberOfFiles();
}

int Backup::getNumberOfPoints() {
    return pointList.size();
}

int Backup::getSumOfSizesOfPoints() {
    int sizeSum = 0;
    for (auto i = pointList.begin(); i != pointList.end(); i++) {
        sizeSum += i->getSizeOfPoint();
    }
    return sizeSum;
}

vector<BackUpPoint> Backup::getPointList(){
    return pointList;
}

vector<BackUpPoint>& Backup::getPointListLink(){
    return pointList;
}

void Backup::setPointList(vector<BackUpPoint> newPointList) {
    this->pointList = newPointList;
}
