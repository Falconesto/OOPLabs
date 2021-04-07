//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_TRANSACTION_H
#define LAB5_TRANSACTION_H


class Transaction {
private:
    int from;
    int to;
    int howMuch;
public:
    Transaction(int from, int to, int howMuch);

    int getFrom();

    int getTo();

    int getHowMuch();
};


#endif //LAB5_TRANSACTION_H
