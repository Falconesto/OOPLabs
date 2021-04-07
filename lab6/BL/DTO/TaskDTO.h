//
// Created by Александр on 14.12.2020.
//

#ifndef LAB6_TASKDTO_H
#define LAB6_TASKDTO_H


#include "EmployeeDTO.h"
#include "EntitieDTO.h"

class TaskDTO : public EntitieDTO  {
public:
    string name;
    string description;
    string comment = "";
    EmployeeDTO* solver;
    taskState state;
    bool changed = false;
    Time timeOfCreation;

    EmployeeDTO *getSolver() const;

    Time &getTimeOfCreation();

    TaskDTO(int id, string name, string description, Time time);

    void changeSolver(EmployeeDTO* newSolver);

    void changeState();

    bool isChanged() const;

    void setChanged(bool changed);
};



#endif //LAB6_TASKDTO_H
