//
// Created by Александр on 10.10.2020.
//

#include "Shop.h"

Shop::Shop(int newCode, string newName, string newAddress) {
    this->code = newCode;
    this->name = newName;
    this->address = newAddress;
}

Shop::Shop() {
    this->code = -1;
    this->name = "";
    this->address = "";
}

const int Shop::getCode() {
    return this->code;
}

const string Shop::getName() {
    return this->name;
}