//
// Created by Александр on 13.12.2020.
//

#include "Employee.h"

Employee::Employee(int id, string name) {
    this->name = name;
    this->id = id;
}

void Employee::changeBoss(Employee *newBoss) {
    this->boss = newBoss;
}

int Employee::getId() {
    return this->id;
}

Employee::Employee() {
    this->name = "";
    this->id = -1;
}
