//
// Created by Александр on 14.12.2020.
//

#include "TaskManagerService.h"

TaskManagerService::TaskManagerService() {

}

TaskDTO TaskManagerService::findByID(int id) {
    Task tmpTask = this->bellowData.findByID(id);
    TaskDTO tmpTaskDTO(tmpTask.id, tmpTask.name, tmpTask.description, tmpTask.timeOfCreation);
    return tmpTaskDTO;
}

vector<TaskDTO> TaskManagerService::findByTime(Time tm) {
    vector<Task> tmpTask = this->bellowData.findByTime(tm);
    vector<TaskDTO> res;
    for (auto tmpt : tmpTask) {
        TaskDTO tmpTaskDTO(tmpt.id, tmpt.name, tmpt.description, tmpt.timeOfCreation);
        res.push_back(tmpTaskDTO);
    }
    return res;
}

vector<TaskDTO> TaskManagerService::findBySolver(EmployeeDTO solver) {
    vector<Task> tmpTask = this->bellowData.findBySolver(solver);
    vector<TaskDTO> res;
    for (auto tmpt : tmpTask) {
        TaskDTO tmpTaskDTO(tmpt.id, tmpt.name, tmpt.description, tmpt.timeOfCreation);
        res.push_back(tmpTaskDTO);
    }
    return res;
}

vector<TaskDTO> TaskManagerService::findByChanged() {
    vector<Task> tmpTask = this->bellowData.findByChanged();
    vector<TaskDTO> res;
    for (auto tmpt : tmpTask) {
        TaskDTO tmpTaskDTO(tmpt.id, tmpt.name, tmpt.description, tmpt.timeOfCreation);
        res.push_back(tmpTaskDTO);
    }
    return res;
}

void TaskManagerService::createTask(string name, string description, EmployeeDTO *solver, Time time) {
    bellowData.createTask(name, description, solver, time);
}

void TaskManagerService::changeTask(int id) {
    bellowData.changeTask(id);
}

void TaskManagerService::changeTaskState(int id) {
    bellowData.changeTaskState(id);
}

void TaskManagerService::addComment(int id, string comment) {
    bellowData.addComment(id, comment);
}

Time TaskManagerService::getTimeOfChange(int id) {
    bellowData.getTimeOfChange(id);
}

void TaskManagerService::changeTaskSolver(int taskId, EmployeeDTO *solver) {
    bellowData.changeTaskSolver(taskId, solver);
}

void TaskManagerService::completeTask(int id) {
    bellowData.changeTask(id);
    bellowData.changeTaskState(id);
}
