//
// Created by Александр on 14.12.2020.
//

#include "ReportManagerService.h"

ReportManagerService::ReportManagerService() {

}

void ReportManagerService::createDayReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, Time time, int id) {
    bellowData.createDayReport(finishedTasks, time, id);
}

void ReportManagerService::createSprintReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, Time time, int id) {
    bellowData.createSprintReport(finishedTasks, time, id);
}
