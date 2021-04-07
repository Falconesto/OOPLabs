//
// Created by Александр on 13.12.2020.
//

#include "EmployeeManagerSystem.h"

EmployeeManagerSystem::EmployeeManagerSystem() {

}

void EmployeeManagerSystem::addEmployee(int id, string name) {
    Employee newEmpl(id, name);
    myEmployee.push_back(newEmpl);
}

void EmployeeManagerSystem::changeBoss(int idEmp, Employee* newBoss) {
    myEmployee[idEmp].changeBoss(newBoss);
}

void EmployeeManagerSystem::showHierarchy() {

}

Employee EmployeeManagerSystem::findEmp(int id) {
    return myEmployee[id];
}
