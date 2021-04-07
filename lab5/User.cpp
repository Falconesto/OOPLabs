//
// Created by Александр on 29.11.2020.
//

#include "User.h"

User::User(string newFirstName, string newSecondName) {
    this->firstName = newFirstName;
    this->secondName = newSecondName;
}

User::User() {

}

void User::setAddress(string newAddress) {
    this->address = newAddress;
    if(this->passportNum != -1){
        this->verified = true;
    }
}

void User::setPassportNum(int newPassportNum) {
    this->passportNum = newPassportNum;
    if(this->address != ""){
        this->verified = true;
    }
}

bool User::getVerified() {
    return this->verified;
}
