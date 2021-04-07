//
// Created by Александр on 19.10.2020.
//

#include "shopDetails.h"

shopDetails::shopDetails(Shop newThisShop, map<int, shopStock> newEntireMarket) {
    thisShop = newThisShop;
    entireMarket = newEntireMarket;
}

shopDetails::shopDetails() {
    thisShop = Shop();
    entireMarket = {};
}

Shop shopDetails::getShop() {
    return this->thisShop;
}

map<int, shopStock>& shopDetails::getEntireMarket(){
    return this->entireMarket;
}

pair<int, int> shopDetails::findTheCheapestInShop(int itemCode){
    map<int, shopStock> tmpMarket=this->getEntireMarket();
    for (const auto&[itemKey, itemValue] : this->getEntireMarket()) {
        if (tmpMarket[itemKey].getItem().getCode() == itemCode) {
            return make_pair(this->getShop().getCode(), tmpMarket[itemKey].getPrice());
        }
    }
}