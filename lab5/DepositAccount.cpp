//
// Created by Александр on 29.11.2020.
//

#include "DepositAccount.h"

DepositAccount::DepositAccount(User myUser, double balance, int accountID, Time dateOfCreation, int forHowManyMonths) {
    this->myUser = myUser;
    this->balance = balance;
    this->accountID = accountID;
    this->monthIncome = 0;
    this->Type = "Deposit";
    this->dateOfCreation = dateOfCreation;
    this->expiringDate = dateOfCreation.getExpiringDate(0, forHowManyMonths, 0);
    this->realDate = dateOfCreation;
}

Transaction DepositAccount::withdrawMoney(int howMuch, int max) {
    if (realDate > expiringDate) {
        if (this->balance - howMuch < 0) {
            throw (string) "There is no enough money";
        }
        if ((this->myUser.getVerified())&&(howMuch > max)) {
            throw (string) "To big transaction for a nonverified account";
        }
        Transaction newTransaction(this->accountID, -1, howMuch);
        return newTransaction;
    } else {
        throw (string) "It is an active deposit account";
    }
}

Transaction DepositAccount::transferMoney(int toAccountID, int howMuch, int max) {
    if (realDate > expiringDate) {
        if (this->balance - howMuch < 0) {
            throw (string) "There is no enough money";
        }
        if ((this->myUser.getVerified())&&(howMuch > max)) {
            throw (string) "To big transaction for a nonverified account";
        }
        Transaction newTransaction(this->accountID, toAccountID, howMuch);
        return newTransaction;
    } else {
        throw (string) "It is an active deposit account";
    }
}
