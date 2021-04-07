//
// Created by Александр on 15.11.2020.
//

#ifndef LAB4_BACKUPPOINT_H
#define LAB4_BACKUPPOINT_H

#include "File.h"
#include "Time.h"
#include <vector>
#include <map>

class BackUpPoint {
private:
    vector<File> pointFiles;
    Time dateOfCreation;
    int sizeOfPointReal = 0;
    int sizeOfPointInc = 0;
    int sizeOfPoint = 0;
    map<string, File> backUpDirectoryList;
    int version;
    bool real;
public:
    BackUpPoint(vector<File> newFiles, Time myDate, bool real, BackUpPoint previousPoint, bool separated);

    BackUpPoint(vector<File> newFiles, Time myDate, bool separated);

    File &findFileWithSameOriginalDirectory(string originalDirectory, vector<File> files);

    string getFileName(string newString);

    int getVersion();

    vector<File> getPointFiles();

    Time getDateOfCreation();

    bool getReal();

    int getSizeOfPoint();

    int getNumberOfFiles();
};


#endif //LAB4_BACKUPPOINT_H
