//
// Created by Александр on 14.12.2020.
//

#include "EmployeeDTO.h"

EmployeeDTO::EmployeeDTO(int id, string name) {
    this->name = name;
    this->id = id;
}

void EmployeeDTO::changeBoss(EmployeeDTO *newBoss) {
    this->boss = newBoss;
}

int EmployeeDTO::getId() {
    return this->id;
}
