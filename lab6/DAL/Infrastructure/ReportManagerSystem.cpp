//
// Created by Александр on 13.12.2020.
//

#include "ReportManagerSystem.h"

ReportManagerSystem::ReportManagerSystem() {

}

void ReportManagerSystem::createDayReport(vector<pair<Employee, Task>> finishedTasks, Time time, int id) {
    Report newRep(finishedTasks, time, myDayReports.size()+1);
    myDayReports.push_back(newRep);
}

void ReportManagerSystem::createSprintReport(vector<pair<Employee, Task>> finishedTasks, Time time, int id) {
    Report newRep(finishedTasks, time, mySprintReports.size()+1);
    mySprintReports.push_back(newRep);
}
