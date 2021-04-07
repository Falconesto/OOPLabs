//
// Created by Александр on 13.12.2020.
//

#ifndef LAB6_TASK_H
#define LAB6_TASK_H

#include "Employee.h"
#include "Entitie.h"

enum taskState {
    Open,
    Active,
    Resolved
};

class Task : public Entitie {
public:
    string name;
    string description;
    string comment = "";
    Employee *solver = new Employee(-1, "");
    taskState state;
    bool changed = false;
    Time timeOfCreation;
    Time timeOfChange;

    Employee *getSolver() const;

    Time &getTimeOfCreation();

    Task(int id, string name, string description, Time time);

    void changeSolver(Employee *newSolver);

    void changeState();

    bool isChanged() const;

    void setChanged(bool changed);
};


#endif //LAB6_TASK_H
