//
// Created by Александр on 15.11.2020.
//

#ifndef LAB4_FILE_H
#define LAB4_FILE_H


#include <string>

using namespace std;

class File {
private:
    int size;
    string originalDirectory;
public:
    File(int size, string originalDirectory);
    File(File const& otherFile);
    int getSize();
    string getOriginalDirectory();
    void setBackupDirectory(string newBackupDirectory);
    bool operator== (const File &f1);
};


#endif //LAB4_FILE_H
