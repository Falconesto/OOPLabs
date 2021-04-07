//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_REPORTDTO_H
#define LAB6_REPORTDTO_H

#include "TaskDTO.h"
#include "EntitieDTO.h"

class ReportDTO : public EntitieDTO {
    vector<pair<EmployeeDTO, TaskDTO>> finishedTasks;
    Time timeOfCreation;

public:
    ReportDTO(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, Time time, int id);

};


#endif //LAB6_REPORTDTO_H
