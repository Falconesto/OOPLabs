#include <iostream>
#include "Interactions.h"

int main() {
    try{
        Bank bank1("Sber", 1);
        User vova("Vova", "Putin");
        User dima("Dima", "Medvedev");
        bank1.createDebitAccount(vova, 500, 0001);
        bank1.createDebitAccount(dima, 400, 0002);
        Bank bank2("SPB", 2);
        bank2.createDebitAccount(vova, 700, 0003);
        bank2.createDebitAccount(dima, 600, 0003);
        Interactions myAction;
        myAction.addBank(bank1);
        myAction.addBank(bank2);
        myAction.createTheTransaction(10001, 10002, 200);
        myAction.interruptTheTransaction(0);
    } catch (string &exception) {
        std::cerr << "Error: " << exception << '\n';
        return 1;
    }
    return 0;
}
