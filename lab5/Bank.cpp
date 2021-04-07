//
// Created by Александр on 29.11.2020.
//

#include "Bank.h"

Bank::Bank(string bankName, int bankID) {
    this->bankName = bankName;
    this->bankID = bankID;
}

void Bank::createDepositAccount(User myUser, double balance, int accountID, Time dateOfCreation, int forHowManyMonths) {
    DepositAccount newAccount(myUser, balance, accountID, dateOfCreation, forHowManyMonths);
    bankAccounts.push_back(newAccount);
}

void Bank::createDebitAccount(User myUser, double balance, int accountID) {
    DebitAccount newAccount(myUser, balance, accountID);
    bankAccounts.push_back(newAccount);
}

void Bank::createCreditAccount(User myUser, double balance, int accountID) {
    CreditAccount newAccount(myUser, balance, accountID, defaultCreditLimit, defaultCommissions);
    bankAccounts.push_back(newAccount);
}

void Bank::dayIncome() {
    for (auto acc : bankAccounts) {
        if (acc.getType() != "Credit") {
            acc.setMonthIncome(acc.getMonthIncome() + acc.getBalance() * (1 + this->percentIncome));
        }
    }
}

void Bank::monthIncome() {
    for (auto acc : bankAccounts) {
        if (acc.getType() != "Credit") {
            acc.setBalance(acc.getBalance()+acc.getMonthIncome());
            acc.setMonthIncome(0);
        }
    }
}

vector<Account> &Bank::getAccounts() {
    return bankAccounts;
}

int Bank::getMaxTransactionForNonauthorized() {
    return this->maxTransactionForNonauthorized;
}





