//
// Created by Александр on 13.12.2020.
//

#ifndef LAB6_REPORTMANAGERSYSTEM_H
#define LAB6_REPORTMANAGERSYSTEM_H

#include "ManagerSystem.h"

class ReportManagerSystem : public ManagerSystem {
    vector<Report> myDayReports;
    vector<Report> mySprintReports;
public:
    ReportManagerSystem();

    void createDayReport(vector<pair<Employee, Task>> finishedTasks, Time time, int id);

    void createSprintReport(vector<pair<Employee, Task>> finishedTasks, Time time, int id);


};


#endif //LAB6_REPORTMANAGERSYSTEM_H
