//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_EMPLOYEEDTO_H
#define LAB6_EMPLOYEEDTO_H

#include "EntitieDTO.h"

using namespace std;

class EmployeeDTO : public EntitieDTO {
private:
    string name;
    EmployeeDTO *boss;
    vector<EmployeeDTO> subordinates;
public:
    EmployeeDTO(int id, string name);

    void changeBoss(EmployeeDTO* newBoss);

    int getId();
};


#endif //LAB6_EMPLOYEEDTO_H
