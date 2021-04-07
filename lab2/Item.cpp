//
// Created by Александр on 10.10.2020.
//

#include "Item.h"

Item::Item(int newCode, string newName) {
    this->code = newCode;
    this->name = newName;
}

Item::Item() {
    this->code = -1;
    this->name = "";
}

int Item::getCode() const {
    return this->code;
}

string Item::getName() const {
    return this->name;
}