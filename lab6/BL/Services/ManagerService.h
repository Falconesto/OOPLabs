//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_MANAGERSERVICE_H
#define LAB6_MANAGERSERVICE_H

#include "../DTO/TaskDTO.h"
#include "../DTO/ReportDTO.h"
#include "../DTO/EmployeeDTO.h"
#include "../../DAL/Infrastructure/EmployeeManagerSystem.h"
#include "../../DAL/Infrastructure/ReportManagerSystem.h"
#include "../../DAL/Infrastructure/TaskManagerSystem.h"

class ManagerService {
protected:
    ManagerSystem bellowData;
};


#endif //LAB6_MANAGERSERVICE_H
