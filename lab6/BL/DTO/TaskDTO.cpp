//
// Created by Александр on 14.12.2020.
//

#include "TaskDTO.h"

TaskDTO::TaskDTO(int id, string name, string description, Time time) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->state = taskState::Open;
    this->timeOfCreation = time;
}

void TaskDTO::changeSolver(EmployeeDTO *newSolver) {
    this->solver = newSolver;
}

void TaskDTO::changeState() {
    switch (this->state) {
        case taskState::Open:
            this->state = taskState::Active;
            break;
        case taskState::Active:
            this->state = taskState::Resolved;
            break;
        case taskState::Resolved:
            throw (string) "state problem";
            break;
    }
}

Time &TaskDTO::getTimeOfCreation() {
    return timeOfCreation;
}

EmployeeDTO *TaskDTO::getSolver() const {
    return solver;
}

bool TaskDTO::isChanged() const {
    return changed;
}

void TaskDTO::setChanged(bool changed) {
    TaskDTO::changed = changed;
}

