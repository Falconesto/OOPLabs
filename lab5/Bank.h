//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_BANK_H
#define LAB5_BANK_H
#include "CreditAccount.h"
#include "DebitAccount.h"
#include "DepositAccount.h"
#include "vector"

class Bank {
private:
    vector<Account> bankAccounts;
    string bankName;
    int bankID;
    double percentIncome = 0.05;
    int defaultCreditLimit = -1000;
    int defaultCommissions = 20;
    int maxTransactionForNonauthorized = 10000;
public:
    Bank(string bankName, int bankID);

    void dayIncome();

    void monthIncome();

    vector<Account>& getAccounts();

    void createDepositAccount(User myUser, double balance, int accountID, Time dateOfCreation, int forHowManyMonths);

    void createDebitAccount(User myUser, double balance, int accountID);

    void createCreditAccount(User myUser, double balance, int accountID);

    int getMaxTransactionForNonauthorized();
};


#endif //LAB5_BANK_H
