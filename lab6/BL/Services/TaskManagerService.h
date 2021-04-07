//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_TASKMANAGERSERVICE_H
#define LAB6_TASKMANAGERSERVICE_H

#include "ManagerService.h"


class TaskManagerService : public ManagerService {
    TaskManagerSystem bellowData;
public:
    TaskManagerService();

    TaskDTO findByID(int id);

    vector<TaskDTO> findByTime(Time tm);

    vector<TaskDTO> findBySolver(EmployeeDTO solver);

    vector<TaskDTO> findByChanged();

    void createTask(string name, string description, EmployeeDTO* solver, Time time);

    void changeTask(int id);

    void changeTaskState(int id);

    void addComment(int id, string comment);

    Time getTimeOfChange(int id);

    void changeTaskSolver(int taskId, EmployeeDTO* solver);

    void completeTask(int id);

};


#endif //LAB6_TASKMANAGERSERVICE_H
