#include <iostream>
#include "PL/Action.h"

int main() {
    Action myAction;
    myAction.addEmployee(1, "Petya");
    myAction.addEmployee(2, "Slava");
    myAction.addEmployee(3, "Liza");
    myAction.changeBoss(1, 2);

    myAction.createTask("lab6", "kapec real'no", 1);
    myAction.changeTask(1);
    myAction.changeTaskState(1);
    cout << myAction.getTimeOfChange(1);
    cout << myAction.findByChanged();
    return 0;
}
