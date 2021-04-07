//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_ACCOUNT_H
#define LAB5_ACCOUNT_H
#include "User.h"
#include "Transaction.h"

class Account {
protected:
    User myUser;
    double balance;
    int accountID;
    string Type;
    double monthIncome;
public:
    string getType();
    int getBalance();
    double getMonthIncome();
    void setMonthIncome(double newMonthIncome);
    void setBalance(int newBalance);
    virtual Transaction withdrawMoney(int howMuch, int max);
    Transaction depositMoney(int howMuch);
    virtual Transaction transferMoney(int toAccountID, int howMuch, int max);
};


#endif //LAB5_ACCOUNT_H
