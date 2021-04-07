#include <iostream>
#include "ExpiredByDate.h"
#include "ExpiredBySize.h"
#include "ExpiredByNumber.h"
#include "ExpiredByMixed.h"

int main() {
    try{
        Time myTime;

        File file1A(100, "Home\\Files\\FileA");
        File file1B(100, "Home\\Files\\FileB");
        Backup first({file1A, file1B}, myTime, true);
        cout << first.getNumberOfFilesInLastBackUpPoint() << endl;
        File file1A_1(110, "Home\\Files\\FileA");
        File file1B_1(110, "Home\\Files\\FileB");
        first.addNewBackUpPoint({file1A_1, file1B_1}, myTime, true);
        ExpiredByNumber check1(1);
        check1.checkForExpiredPoints(first);
        cout << first.getNumberOfPoints() << endl;
        cout << endl;

        File file2A(50, "Home\\Files\\FileA");
        File file2B(50, "Home\\Files\\FileB");
        Backup second({file2A, file2B}, myTime, true);
        File file2A_1(50, "Home\\Files\\FileA");
        File file2B_1(50, "Home\\Files\\FileB");
        second.addNewBackUpPoint({file2A_1, file2B_1}, myTime, true);
        cout << second.getNumberOfPoints() << endl;
        cout << second.getSumOfSizesOfPoints() << endl;
        ExpiredBySize check2(150);
        check2.checkForExpiredPoints(second);
        cout << second.getNumberOfPoints() << endl;
        cout << endl;

        File file3A(50, "Home\\Files\\FileA");
        File file3B(50, "Home\\Files\\FileB");
        Backup third({file3A, file3B}, myTime, true);
        File file3A_1(60, "Home\\Files\\FileA");
        File file3B_1(60, "Home\\Files\\FileB");
        third.addNewBackUpPoint({file3A_1, file3B_1}, myTime, false);
        cout << third.getNumberOfPoints() << endl;
        cout << third.getSumOfSizesOfPoints() << endl;
        cout << endl;

        File file4A(50, "Home\\Files\\FileA");
        File file4B(50, "Home\\Files\\FileB");
        Backup fourth({file4A, file4B}, myTime, true);
        File file4A_1(60, "Home\\Files\\FileA");
        File file4B_1(60, "Home\\Files\\FileB");
        fourth.addNewBackUpPoint({file4A_1, file4B_1}, myTime, true);
        cout << fourth.getNumberOfPoints() << endl;
        cout << fourth.getSumOfSizesOfPoints() << endl;
        ExpiredBySize check4_1(150);
        ExpiredByNumber check4_2(2);
        ExpiredByMixed check4({&check4_1, &check4_2}, true);
        check4.checkForExpiredPoints(fourth);
        cout << fourth.getNumberOfPoints() << endl;
        cout << fourth.getSumOfSizesOfPoints() << endl;
        cout << endl;

        File file5A(50, "Home\\Files\\FileA");
        File file5B(50, "Home\\Files\\FileB");
        Backup fifth({file5A, file5B}, myTime, true);
        File file5A_1(60, "Home\\Files\\FileA");
        File file5B_1(60, "Home\\Files\\FileB");
        fifth.addNewBackUpPoint({file5A_1, file5B_1}, myTime, true);
        cout << fifth.getNumberOfPoints() << endl;
        cout << fifth.getSumOfSizesOfPoints() << endl;
        myTime.travelToTheFuture(0, 2, 0);
        ExpiredByDate check5_1(myTime);
        ExpiredByNumber check5_2(2);
        ExpiredByMixed check5({&check5_1, &check5_2}, true);
        check5.checkForExpiredPoints(fifth);
        cout << fifth.getNumberOfPoints() << endl;
        cout << fifth.getSumOfSizesOfPoints() << endl;
        cout << endl;

    } catch (string &exception) {
        std::cerr << "Error: " << exception << '\n';
        return 1;
    }
    return 0;
}
