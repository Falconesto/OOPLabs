//
// Created by Александр on 13.12.2020.
//

#include "Task.h"

Task::Task(int id, string name, string description, Time time) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->state = taskState::Open;
    this->timeOfCreation = time;
}

void Task::changeSolver(Employee *newSolver) {
    this->solver = newSolver;
}

void Task::changeState() {
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

Time &Task::getTimeOfCreation() {
    return timeOfCreation;
}

Employee* Task::getSolver() const {
    return solver;
}

bool Task::isChanged() const {
    return changed;
}

void Task::setChanged(bool changed) {
    Task::changed = changed;
}


