//
// Created by Александр on 13.12.2020.
//

#ifndef LAB6_EMPLOYEEMANAGERSYSTEM_H
#define LAB6_EMPLOYEEMANAGERSYSTEM_H

#include "ManagerSystem.h"

class EmployeeManagerSystem : public ManagerSystem {
public:
    vector<Employee> myEmployee;

    EmployeeManagerSystem();

    void addEmployee(int id, string name);

    void changeBoss(int idEmp, Employee* newBoss);

    void showHierarchy();

    Employee findEmp(int id);
};


#endif //LAB6_EMPLOYEEMANAGERSYSTEM_H
