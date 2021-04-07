//
// Created by Александр on 29.11.2020.
//

#include "CreditAccount.h"

CreditAccount::CreditAccount(User myUser, double balance, int accountID, double limit, double commission) {
    this->myUser = myUser;
    this->balance = balance;
    this->accountID = accountID;
    this->Type = "Credit";
    this->limit = limit;
    this->commission = commission;
    this->monthIncome = 0;
}

Transaction CreditAccount::withdrawMoney(int howMuch, int max) {
    if(this->balance - howMuch < limit){
        throw (string) "There is no enough money";
    }
    if ((this->myUser.getVerified())&&(howMuch > max)) {
        throw (string) "To big transaction for a nonverified account";
    }
    Transaction newTransaction(this->accountID, -1, howMuch);
    return newTransaction;
}

Transaction CreditAccount::transferMoney(int toAccountID, int howMuch, int max) {
    if(this->balance - howMuch < limit){
        throw (string) "There is no enough money";
    }
    if ((this->myUser.getVerified())&&(howMuch > max)) {
        throw (string) "To big transaction for a nonverified account";
    }
    Transaction newTransaction(this->accountID, toAccountID, howMuch);
    return newTransaction;
}


