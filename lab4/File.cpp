//
// Created by Александр on 15.11.2020.
//

#include "File.h"

File::File(int size, string originalDirectory) {
    this->size = size;
    this->originalDirectory = originalDirectory;
}

File::File(File const&otherFile) {
    this->size = otherFile.size;
    this->originalDirectory = otherFile.originalDirectory;
}

int File::getSize() {
    return this->size;
}

string File::getOriginalDirectory() {
    return originalDirectory;
}


void File::setBackupDirectory(string newBackupDirectory) {

}

bool File::operator==(const File &f1) {
    if (this->originalDirectory == f1.originalDirectory) {
        return true;
    }
    return false;
}


