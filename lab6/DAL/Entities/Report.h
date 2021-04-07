//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_REPORT_H
#define LAB6_REPORT_H

#include "Entitie.h"
#include "Task.h"

class Report : public Entitie {
public:
    vector<pair<Employee, Task>> finishedTasks;
    Time timeOfCreation;


    Report(vector<pair<Employee, Task>> finishedTasks, Time time, int id);

};


#endif //LAB6_REPORT_H
