//
// Created by Александр on 10.10.2020.
//
#include <string>


#ifndef LAB2_ITEM_H
#define LAB2_ITEM_H

using namespace std;

class Item {
private:
    int code;

    string name;

public:
    Item(int newCode, string newName);

    Item();

    int getCode() const;

    string getName() const;
};


#endif //LAB2_ITEM_H
