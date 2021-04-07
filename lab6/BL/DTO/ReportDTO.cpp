//
// Created by Александр on 14.12.2020.
//

#include "ReportDTO.h"

ReportDTO::ReportDTO(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, Time time, int id) {
    this->id = id;
    this->finishedTasks = finishedTasks;
    this->timeOfCreation = time;
}
