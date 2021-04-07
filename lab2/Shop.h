//
// Created by Александр on 10.10.2020.
//

#include <string>


#ifndef LAB2_SHOP_H
#define LAB2_SHOP_H

using namespace std;

class Shop {
private:
    unsigned int code;
    string name;
    string address;

public:
    Shop(int newCode, string newName, string newAddress);

    Shop();

    const int getCode();

    const string getName();

};


#endif //LAB2_SHOP_H
