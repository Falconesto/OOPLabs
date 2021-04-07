//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_EMPLOYEEMANAGERSERVICE_H
#define LAB6_EMPLOYEEMANAGERSERVICE_H

#include "ManagerService.h"

class EmployeeManagerService : public ManagerService {
    EmployeeManagerSystem bellowData;
public:
    EmployeeManagerService();

    void addEmployee(int id, string name);

    void changeBoss(int idEmp, EmployeeDTO* newBoss);

    void showHierarchy();

    EmployeeDTO getEmployee(int id);
};



#endif //LAB6_EMPLOYEEMANAGERSERVICE_H
