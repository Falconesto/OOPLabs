//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_REPORTMANAGERSERVICE_H
#define LAB6_REPORTMANAGERSERVICE_H

#include "ManagerService.h"

class ReportManagerService : public ManagerService {
    ReportManagerSystem bellowData;

public:
    ReportManagerService();

    void createDayReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, Time time, int id);

    void createSprintReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, Time time, int id);


};



#endif //LAB6_REPORTMANAGERSERVICE_H
