//
// Created by Александр on 19.10.2020.
//

#include "shopStock.h"

shopStock::shopStock() {
    item = Item();
    amount = 0;
    price = 0;
}

Item shopStock::getItem() {
    return this->item;
}

int shopStock::getAmount() {
    return this->amount;
}

int shopStock::getPrice() {
    return this->price;
}

void shopStock::setAmount(int newAmount){
    this->amount=newAmount;
}

void shopStock::setPrice(int newPrice){
    this->price=newPrice;
}

void shopStock::setItem(Item newItem){
    this->item=newItem;
}