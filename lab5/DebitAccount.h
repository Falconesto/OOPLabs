//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_DEBITACCOUNT_H
#define LAB5_DEBITACCOUNT_H

#include "Account.h"

class DebitAccount : public Account {
private:
    double monthIncome;
public:
    DebitAccount(User myUser, double balance, int accountID);
    Transaction withdrawMoney(int howMuch, int max);
    Transaction transferMoney(int toAccountID, int howMuch, int max);
};


#endif //LAB5_DEBITACCOUNT_H
