//
// Created by Александр on 13.12.2020.
//

#include "TaskManagerSystem.h"

TaskManagerSystem::TaskManagerSystem() {

}

Task TaskManagerSystem::findByID(int id) {
    return myTasks[id];
}

vector<Task> TaskManagerSystem::findByTime(Time tm) {
    vector<Task> res;
    for(auto task : myTasks){
        if(tm == task.getTimeOfCreation()){
            res.push_back(task);
        }
    }
    return res;
}

vector<Task> TaskManagerSystem::findBySolver(Employee solver) {
    vector<Task> res;
    for(auto task : myTasks){
        if(solver.getId() == task.getSolver()->getId()){
            res.push_back(task);
        }
    }
    return res;
}

vector<Task> TaskManagerSystem::findByChanged() {
    vector<Task> res;
    for(auto task : myTasks){
        if(task.isChanged()){
            res.push_back(task);
        }
    }
    return res;
}

void TaskManagerSystem::createTask(string name, string description, Employee *solver, Time time) {
    Task newTask(this->myTasks.size()+1, name, description, time);
    myTasks.push_back(newTask);
}

void TaskManagerSystem::changeTask(int id) {
    myTasks[id].setChanged(true);
}

void TaskManagerSystem::changeTaskState(int id) {
    myTasks[id].changeState();
}

void TaskManagerSystem::addComment(int id, string comment) {
    myTasks[id].comment+=" " + comment;
}

Time TaskManagerSystem::getTimeOfChange(int id) {
    return myTasks[id].timeOfChange;
}

void TaskManagerSystem::changeTaskSolver(int id, Employee *solver) {
    myTasks[id].changeSolver(solver);
}
