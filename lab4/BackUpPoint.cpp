//
// Created by Александр on 15.11.2020.
//

#include "BackUpPoint.h"

BackUpPoint::BackUpPoint(vector<File> newFiles, Time myDate, bool separated) {
    this->pointFiles = newFiles;
    this->dateOfCreation = myDate;
    this->real = true;
    this->version = 1;
    for (int i = 0; i < this->pointFiles.size(); i++) {
        this->sizeOfPointReal += pointFiles[i].getSize();
        string fileName = getFileName(pointFiles[i].getOriginalDirectory());
        string backUpDirectoryName;
        if (separated) {
            backUpDirectoryName =
                    "Home\\Backups\\backup" + to_string(version) + "\\" + fileName + "\\" + fileName + "_" +
                    to_string(version);
        } else {
            backUpDirectoryName =
                    "Home\\Backups\\backup" + to_string(version) + "\\" + fileName + "_" + to_string(version);
        }
        backUpDirectoryList.insert(make_pair(backUpDirectoryName, pointFiles[i]));
    }
    this->sizeOfPointInc = 0;
    this->sizeOfPoint = this->sizeOfPointReal;
}

BackUpPoint::BackUpPoint(vector<File> newFiles, Time myDate, bool real, BackUpPoint previousPoint, bool separated) {
    this->pointFiles = newFiles;
    this->dateOfCreation = myDate;
    this->real = real;
    this->version = previousPoint.getVersion() + 1;
    if (this->real) {
        for (int i = 0; i < this->pointFiles.size(); i++) {
            this->sizeOfPointReal += pointFiles[i].getSize();
            string fileName = getFileName(pointFiles[i].getOriginalDirectory());
            string backUpDirectoryName;
            if (separated) {
                backUpDirectoryName =
                        "Home\\Backups\\backup" + to_string(version) + "\\" + fileName + "\\" + fileName + "_" +
                        to_string(version);
            } else {
                backUpDirectoryName =
                        "Home\\Backups\\backup" + to_string(version) + "\\" + fileName + "_" + to_string(version);
            }
            backUpDirectoryList.insert(make_pair(backUpDirectoryName, pointFiles[i]));
        }
        this->sizeOfPointInc = 0;
        this->sizeOfPoint = this->sizeOfPointReal;
    } else {
        for (int i = 0; i < this->pointFiles.size(); i++) {
            File previousFile = this->findFileWithSameOriginalDirectory(pointFiles[i].getOriginalDirectory(),
                                                                        previousPoint.getPointFiles());
            vector<File> tmp = previousPoint.getPointFiles();
            this->sizeOfPointInc += pointFiles[i].getSize() - previousFile.getSize();
            this->sizeOfPointReal += pointFiles[i].getSize();
            if (pointFiles[i].getSize() - previousFile.getSize() < 0) {
                throw (string) "New file must not have smaller size then the previous one" +
                      pointFiles[i].getOriginalDirectory();
            }
            string fileName = getFileName(pointFiles[i].getOriginalDirectory());
            string backUpDirectoryName;
            if (separated) {
                backUpDirectoryName =
                        "Home\\Backups\\backup" + to_string(version) + "\\" + fileName + "\\" + fileName + "_" +
                        to_string(version);
            } else {
                backUpDirectoryName =
                        "Home\\Backups\\backup" + to_string(version) + "\\" + fileName + "_" + to_string(version);
            }
            backUpDirectoryList.insert(make_pair(backUpDirectoryName, pointFiles[i]));
        }
        this->sizeOfPoint = this->sizeOfPointInc;
    }
}

string BackUpPoint::getFileName(string newString) {
    char sep = '\\';
    string s = newString;
    vector<string> tmp;

    for (size_t p = 0, q = 0; p != s.npos; p = q) {
        tmp.push_back(s.substr(p + (p != 0), (q = s.find(sep, p + 1)) - p - (p != 0)));
    }
    return tmp.back();
}

File &BackUpPoint::findFileWithSameOriginalDirectory(string originalDirectory, vector<File> files) {
    for (int i = 0; i < this->pointFiles.size(); i++) {
        if (files[i].getOriginalDirectory() == originalDirectory) {
            return files[i];
        }
    }
    throw (string) "There's no such file in previous backup point" + originalDirectory;
}

int BackUpPoint::getVersion() {
    return version;
}

vector<File> BackUpPoint::getPointFiles() {
    return pointFiles;
}

Time BackUpPoint::getDateOfCreation() {
    return dateOfCreation;
}

bool BackUpPoint::getReal() {
    return real;
}

int BackUpPoint::getSizeOfPoint() {
    return sizeOfPoint;
}

int BackUpPoint::getNumberOfFiles() {
    return pointFiles.size();
}



