//
// Created by Александр on 14.12.2020.
//

#include "EmployeeManagerService.h"

EmployeeManagerService::EmployeeManagerService() {}

void EmployeeManagerService::addEmployee(int id, string name) {
    bellowData.addEmployee(id, name);
}

void EmployeeManagerService::changeBoss(int idEmp, int idBoss) {
    bellowData.changeBoss(newBoss);
}

void EmployeeManagerService::showHierarchy() {
    bellowData.showHierarchy();
}

EmployeeDTO EmployeeManagerService::getEmployee(int id) {
    return bellowData.find(id);
}
