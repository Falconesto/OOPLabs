//
// Created by Александр on 10.10.2020.
//

#include "Action.h"

void Action::createNewShop(int newCode, string newName, string newAddress) {
    if (this->shopList.find(newCode) == shopList.end()) {
        Shop newShop(newCode, newName, newAddress);
        shopDetails thisShopDetails(newShop, {});
        shopList.insert(pair<int, shopDetails>(newCode, thisShopDetails));
    } else {
        throw (string) to_string(newCode) + ": Shop with this ID already exists";
    }
}

void Action::createNewItem(int newCode, string newName) {
    if (this->itemlist.find(newCode) == itemlist.end()) {
        Item newItem(newCode, newName);
        itemlist.insert(pair<int, Item>(newCode, newItem));
    } else {
        throw (string) to_string(newCode) + ": Item with this ID already exists";
    }
}

void Action::supplyShopWithItem(int shopCode, int itemCode, int newAmount, int newPrice) {
    if (this->shopList.find(shopCode) != shopList.end()) {
        if (this->itemlist.find(itemCode) != itemlist.end()) {
            if(shopList[shopCode].getEntireMarket().find(itemCode) == shopList[shopCode].getEntireMarket().end()){
                shopList[shopCode].getEntireMarket()[itemCode]=shopStock();
            }
            shopList[shopCode].getEntireMarket()[itemCode].setAmount(
                    shopList[shopCode].getEntireMarket()[itemCode].getAmount() + newAmount);
            shopList[shopCode].getEntireMarket()[itemCode].setPrice(newPrice);
            shopList[shopCode].getEntireMarket()[itemCode].setItem(itemlist[itemCode]);
        } else {
            throw (string) to_string(itemCode) + ": There is no such item in the list";
        }
    } else {
        throw (string) to_string(shopCode) + ": There is no such shop in the list";
    }
}

int Action::findTheCheapestWithinShops(int itemCode) {
    int minPrice = INT_MAX;
    int minShopID = -1;
    for (const auto&[shopKey, shopValue] : shopList) {
        pair<int, int> newInfo = shopList[shopKey].findTheCheapestInShop(itemCode);
        if(newInfo.second<= minPrice){
            minPrice=newInfo.second;
            minShopID = newInfo.first;
        }
    }
    if (minPrice == INT_MAX) {
        throw (string) "Not available at the moment";
    } else {
        return minShopID;
    }
}

void Action::howMuchItemsForMoney(int shopCode, int money) {
    if (this->shopList.find(shopCode) != shopList.end()) {
        for (const auto&[key, value] : shopList[shopCode].getEntireMarket()) {
            int howMuch = money / shopList[shopCode].getEntireMarket()[key].getPrice();
            int code = shopList[shopCode].getEntireMarket()[key].getItem().getCode();
            string name = shopList[shopCode].getEntireMarket()[key].getItem().getName();
            cout << "for " << money << " you can buy " << howMuch << " of " << name << " which ID is "
                 << code << '\n';
        }
    } else {
        throw (string) to_string(shopCode) + ": There is no such shop in the list";
    }
}

int Action::buyBatchOfItems(vector <pair<int, int>> batch, int shopCode, bool doYouWantToBuy) {
    int sum = 0;
    if (this->shopList.find(shopCode) != shopList.end()) {
        for (const auto&[itemCode, amount] : batch) {
            if (shopList[shopCode].getEntireMarket().find(itemCode) != shopList[shopCode].getEntireMarket().end()) {
                if (doYouWantToBuy) {
                    if (amount <= shopList[shopCode].getEntireMarket()[itemCode].getAmount()) {
                        shopList[shopCode].getEntireMarket()[itemCode].setAmount(
                                shopList[shopCode].getEntireMarket()[itemCode].getAmount() - amount);
                        sum += amount * shopList[shopCode].getEntireMarket()[itemCode].getPrice();
                    } else {
                        throw (string) to_string(itemCode) + to_string(amount) +
                              ": We don't have so many items in this shop";
                    }
                } else {
                    if (amount <= shopList[shopCode].getEntireMarket()[itemCode].getAmount()) {
                        sum += amount * shopList[shopCode].getEntireMarket()[itemCode].getPrice();
                    } else {
                        return INT_MAX;
                    }
                }
            } else {
                throw (string) to_string(itemCode) + ": There is no such item in this shop";
            }
        }
    } else {
        throw (string) to_string(shopCode) + ": There is no such shop in the list";
    }
    return sum;
}

int Action::findCheapestBatchInShops(vector <pair<int, int>> batch) {
    int bestShopID = -1;
    int minSum = INT_MAX;
    for (const auto&[key, value] : shopList) {
        int tmpSum = buyBatchOfItems(batch, key, false);
        if (tmpSum <= minSum) {
            minSum = tmpSum;
            bestShopID = shopList[key].getShop().getCode();
        }
    }
    if (minSum == INT_MAX) {
        throw (string) "Not available at the moment";
    } else {
        return bestShopID;
    }
}



