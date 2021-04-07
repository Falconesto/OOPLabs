//
// Created by Александр on 14.12.2020.
//

#include "Report.h"

Report::Report(vector<pair<Employee, Task>> finishedTasks, Time time, int id) {
    this->id = id;
    this->finishedTasks = finishedTasks;
    this->timeOfCreation = time;
}
