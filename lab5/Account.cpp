//
// Created by Александр on 29.11.2020.
//

#include "Account.h"


Transaction Account::depositMoney(int howMuch) {
    Transaction newTransaction(-1, this->accountID, howMuch);
    return newTransaction;
}

string Account::getType() {
    return this->Type;
}

int Account::getBalance() {
    return this->balance;
}

void Account::setBalance(int newBalance) {
    this->balance = newBalance;
}

double Account::getMonthIncome() {
    return monthIncome;
}

void Account::setMonthIncome(double newMonthIncome) {
    this->monthIncome = newMonthIncome;
}

