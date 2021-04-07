//
// Created by Александр on 13.12.2020.
//

#ifndef LAB6_ACTION_H
#define LAB6_ACTION_H

#include "../BL/Services/TaskManagerService.h"
#include "../BL/Services/EmployeeManagerService.h"
#include "../BL/Services/ReportManagerService.h"


class Action {
private:
    TaskManagerService TS;
    ReportManagerService RS;
    EmployeeManagerService ES;
    Time realTime;
public:
    void addEmployee(int id, string name);

    void changeBoss(int idEmp, int idBoss);

    void showHierarchy();

    void createDayReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, int id);

    void createSprintReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, int id);

    string findByID(int id);

    string findByTime(Time tm);

    string findBySolver(EmployeeDTO solver);

    string findByChanged();

    void createTask(string name, string description, int solverId);

    void changeTask(int id);

    void changeTaskState(int id);

    void addComment(int id, string comment);

    string getTimeOfChange(int id);

    void changeTaskSolver(int id, EmployeeDTO* solver);

    void completeTask(int id);

    void nextDay();
};


#endif //LAB6_ACTION_H
