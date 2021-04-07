//
// Created by Александр on 30.11.2020.
//

#include "Interactions.h"

Interactions::Interactions() {}

void Interactions::addBank(Bank newBank) {
    myBanks.push_back(newBank);
}

void Interactions::createTheTransaction(int from, int to, int howMuch) {
    if (from == -1) {
        int max = myBanks[fromCardNumToBank(to)].getMaxTransactionForNonauthorized();
        myBanks[fromCardNumToBank(to)].getAccounts()[fromCardNumToAccount(to)].depositMoney(howMuch, max);
    } else {
        if (to == -1) {
            myBanks[fromCardNumToBank(from)].getAccounts()[fromCardNumToAccount(from)].withdrawMoney(howMuch);
        } else {
            myBanks[fromCardNumToBank(to)].getAccounts()[fromCardNumToAccount(to)].depositMoney(howMuch, max);
            myBanks[fromCardNumToBank(from)].getAccounts()[fromCardNumToAccount(from)].withdrawMoney(howMuch);
        }
    }
    Transaction newTransaction(from, to, howMuch);
    myTransactions.push_back(newTransaction);
}

void Interactions::interruptTheTransaction(int transactionID) {
    int from = myTransactions[transactionID].getFrom();
    int to = myTransactions[transactionID].getTo();
    int howMuch = myTransactions[transactionID].getHowMuch();
    if (from == -1) {
        myBanks[fromCardNumToBank(to)].getAccounts()[fromCardNumToAccount(to)].setBalance(
                myBanks[fromCardNumToBank(to)].getAccounts()[fromCardNumToAccount(to)].getBalance() - howMuch);
    } else {
        if (to == -1) {
            myBanks[fromCardNumToBank(from)].getAccounts()[fromCardNumToAccount(from)].setBalance(
                    myBanks[fromCardNumToBank(from)].getAccounts()[fromCardNumToAccount(from)].getBalance() + howMuch);
        } else {
            myBanks[fromCardNumToBank(to)].getAccounts()[fromCardNumToAccount(to)].setBalance(
                    myBanks[fromCardNumToBank(to)].getAccounts()[fromCardNumToAccount(to)].getBalance() - howMuch);
            myBanks[fromCardNumToBank(from)].getAccounts()[fromCardNumToAccount(from)].setBalance(
                    myBanks[fromCardNumToBank(from)].getAccounts()[fromCardNumToAccount(from)].getBalance() + howMuch);
        }
    }
    myTransactions.erase(myTransactions.begin() + transactionID);
}

void Interactions::nextDay() {
    if (dayCount < 30) {
        for (auto bank : myBanks) {
            bank.dayIncome();
        }
        dayCount++;
    } else {
        this->nextMonth();
        dayCount -= 30;
    }
}

void Interactions::nextMonth() {
    for (auto bank : myBanks) {
        bank.monthIncome();
    }
}

int Interactions::fromCardNumToBank(int cardNum) {
    return (cardNum / 10000);
}

int Interactions::fromCardNumToAccount(int cardNum) {
    return (cardNum % 10000);
}


