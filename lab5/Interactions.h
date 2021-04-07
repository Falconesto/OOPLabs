//
// Created by Александр on 30.11.2020.
//

#ifndef LAB5_INTERACTIONS_H
#define LAB5_INTERACTIONS_H

#include "Bank.h"



class Interactions {
private:
    vector<Bank> myBanks;
    vector<Transaction> myTransactions;
    int dayCount = 0;
public:
    Interactions();

    void addBank(Bank newBank);

    void createTheTransaction(int from, int to, int howMuch);

    void interruptTheTransaction(int transactionID);

    void nextDay();

    void nextMonth();

    int fromCardNumToBank(int cardNum);

    int fromCardNumToAccount(int cardNum);
};


#endif //LAB5_INTERACTIONS_H
