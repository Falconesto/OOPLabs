//
// Created by Александр on 29.11.2020.
//

#include "DebitAccount.h"

DebitAccount::DebitAccount(User myUser, double balance, int accountID) {
    this->myUser = myUser;
    this->balance = balance;
    this->accountID = accountID;
    this->Type = "Debit";
}

Transaction DebitAccount::withdrawMoney(int howMuch, int max) {
    if (this->balance - howMuch < 0) {
        throw (string) "There is no enough money";
    }
    if (!(this->myUser.getVerified())&&(howMuch > max)) {
        throw (string) "To big transaction for a nonverified account";
    }
    Transaction newTransaction(this->accountID, -1, howMuch);
    return newTransaction;
}

Transaction DebitAccount::transferMoney(int toAccountID, int howMuch, int max) {
    if (this->balance - howMuch < 0) {
        throw (string) "There is no enough money";
    }
    if ((this->myUser.getVerified())&&(howMuch > max)) {
        throw (string) "To big transaction for a nonverified account";
    }
    Transaction newTransaction(this->accountID, toAccountID, howMuch);
    return newTransaction;
}


