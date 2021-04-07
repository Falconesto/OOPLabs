//
// Created by Александр on 10.10.2020.
//

#ifndef LAB2_ACTION_H
#define LAB2_ACTION_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "shopDetails.h"

class Action{
private:
    map<int, shopDetails> shopList;
    map<int, Item> itemlist;
public:
    void createNewShop(int newCode, string newName, string newAddress);

    void createNewItem(int newCode, string newName);

    void supplyShopWithItem(int shopCode, int itemCode, int amount, int price);

    int findTheCheapestWithinShops(int itemCode);

    void howMuchItemsForMoney(int shopCode, int money);

    int buyBatchOfItems(vector<pair<int, int>> batch, int shopCode, bool doYouWantToBuy);

    int findCheapestBatchInShops(vector<pair<int, int>> batch);
};


#endif //LAB2_ACTION_H
