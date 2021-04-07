//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_DEPOSITACCOUNT_H
#define LAB5_DEPOSITACCOUNT_H

#include "Account.h"
#include "Time.h"

class DepositAccount : public Account {
private:
    Time dateOfCreation;
    Time expiringDate;
    Time realDate;
public:
    DepositAccount(User myUser, double balance, int accountID, Time dateOfCreation, int forHowManyMonths);
    Transaction withdrawMoney(int howMuch, int max);
    Transaction transferMoney(int toAccountID, int howMuch, int max);
};


#endif //LAB5_DEPOSITACCOUNT_H
