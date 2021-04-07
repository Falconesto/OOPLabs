//
// Created by Александр on 19.10.2020.
//

#ifndef LAB2_SHOPDETAILS_H
#define LAB2_SHOPDETAILS_H

#include "shopStock.h"

class shopDetails {
private:
    Shop thisShop;
    map<int, shopStock> entireMarket;
public:
    shopDetails(Shop newThisShop, map<int, shopStock> newEntireMarket);

    shopDetails();

    Shop getShop();

    map<int, shopStock>& getEntireMarket();

    pair<int, int> findTheCheapestInShop(int itemCode);
};


#endif //LAB2_SHOPDETAILS_H
