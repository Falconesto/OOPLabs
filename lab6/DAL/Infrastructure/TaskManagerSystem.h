//
// Created by Александр on 13.12.2020.
//

#ifndef LAB6_TASKMANAGERSYSTEM_H
#define LAB6_TASKMANAGERSYSTEM_H

#include "ManagerSystem.h"

class TaskManagerSystem : public ManagerSystem{
public:
    vector<Task> myTasks;

    TaskManagerSystem();

    Task findByID(int id);

    vector<Task> findByTime(Time tm);

    vector<Task> findBySolver(Employee solver);

    vector<Task> findByChanged();

    void createTask(string name, string description, Employee* solver, Time time);

    void changeTask(int id);

    void changeTaskState(int id);

    void addComment(int id, string comment);

    Time getTimeOfChange(int id);

    void changeTaskSolver(int id, Employee* solver);


};


#endif //LAB6_TASKMANAGERSYSTEM_H
