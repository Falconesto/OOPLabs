//
// Created by Александр on 15.11.2020.
//

#ifndef LAB4_BACKUP_H
#define LAB4_BACKUP_H

#include "BackUpPoint.h"

class Backup {
protected:
    bool separated;
    vector<BackUpPoint> pointList;

public:
    Backup();

    Backup(vector<File>, Time myDate, bool separated);

    void addNewBackUpPoint(vector<File>, Time myDate, bool real);

    int getNumberOfFilesInLastBackUpPoint();

    int getNumberOfPoints();

    int getSumOfSizesOfPoints();

    vector<BackUpPoint> getPointList();

    vector<BackUpPoint>& getPointListLink();

    void setPointList(vector<BackUpPoint> newPointList);
};


#endif //LAB4_BACKUP_H
