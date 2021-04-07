//
// Created by Александр on 29.11.2020.
//

#ifndef LAB5_USER_H
#define LAB5_USER_H
#include "string"
using namespace std;

class User {
private:
    string firstName;
    string secondName;
    string address = "";
    int passportNum = -1;
    bool verified = false;
public:
    User();

    User(string newFirstName, string newSecondName);

    void setAddress(string newAddress);

    void setPassportNum(int newPassportNum);

    bool getVerified();
};


#endif //LAB5_USER_H
