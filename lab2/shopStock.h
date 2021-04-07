//
// Created by Александр on 19.10.2020.
//

#ifndef LAB2_SHOPSTOCK_H
#define LAB2_SHOPSTOCK_H

#include "Item.h"
#include "Shop.h"
#include <map>

class shopStock {
private:
    Item item;
    int amount = 0;
    int price = -1;
public:
    shopStock();

    Item getItem();

    int getAmount();

    int getPrice();

    void setAmount(int newAmount);

    void setPrice(int newPrice);

    void setItem(Item newItem);
};


#endif //LAB2_SHOPSTOCK_H
