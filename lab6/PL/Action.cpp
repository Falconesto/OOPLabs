//
// Created by Александр on 13.12.2020.
//

#include "Action.h"

void Action::addEmployee(int id, string name) {
    ES.addEmployee(id, name);
}

void Action::changeBoss(int idEmp, int idBoss) {
    ES.changeBoss(idEmp, ES.getEmployee(idBoss));
}

void Action::showHierarchy() {
    ES.showHierarchy();
}

void Action::createDayReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, int id) {
    RS.createDayReport(finishedTasks, realTime, id);
}

void Action::createSprintReport(vector<pair<EmployeeDTO, TaskDTO>> finishedTasks, int id) {
    RS.createSprintReport(finishedTasks, realTime, id);
}

string Action::findByID(int id) {
    TaskDTO tmp = TS.findByID(id);
    string name = tmp.name;
    return name;
}

string Action::findByTime(Time tm) {
    vector<TaskDTO> tmp = TS.findByTime(tm);
    string name = "";
    for(auto task : tmp){
        name+=task.name + " ";
    }
    return name;
}

string Action::findBySolver(EmployeeDTO solver) {
    vector<TaskDTO> tmp = TS.findBySolver(solver);
    string name = "";
    for(auto task : tmp){
        name+=task.name + " ";
    }
    return name;
}

string Action::findByChanged() {
    vector<TaskDTO> tmp = TS.findByChanged();
    string name = "";
    for(auto task : tmp){
        name+=task.name + " ";
    }
    return name;
}

void Action::createTask(string name, string description, int solverId) {
    TS.createTask(name, description, ES.find(solverId), realTime);
}

void Action::changeTask(int id) {
    TS.changeTask(id);
}

void Action::changeTaskState(int id) {
    TS.changeTaskState(id);
}

void Action::addComment(int id, string comment) {
    TS.addComment(id, comment);
}

string Action::getTimeOfChange(int id) {
    Time tmp = TS.getTimeOfChange(id);
    string name = to_string(tmp.year) + " " + to_string(tmp.month) + " " + to_string(tmp.date) ;
    return name;
}

void Action::changeTaskSolver(int id, EmployeeDTO *solver) {
    TS.changeTaskSolver(id, solver);
}

void Action::completeTask(int id) {
    TS.completeTask(id);
}

void Action::nextDay(){
    realTime.travelToTheFuture(0,0,1);
}
