//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_CREDITACCOUNT_H
#define LAB5_CREDITACCOUNT_H

#include "Account.h"


class CreditAccount : public Account {
private:
    double limit;
    double commission;
public:
    CreditAccount(User myUser, double balance, int accountID, double limit, double commission);
    Transaction withdrawMoney(int howMuch, int max);
    Transaction transferMoney(int toAccountID, int howMuch, int max);
};


#endif //LAB5_CREDITACCOUNT_H
