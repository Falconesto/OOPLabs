//
// Created by Александр on 29.11.2020.
//

#include "Transaction.h"

Transaction::Transaction(int from, int to, int howMuch) {
    this->from = from;
    this->to = to;
    this->howMuch = howMuch;
}

int Transaction::getFrom() {
    return from;
}

int Transaction::getTo() {
    return to;
}

int Transaction::getHowMuch() {
    return howMuch;
}
