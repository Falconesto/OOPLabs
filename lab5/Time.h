//
// Created by Александр on 30.11.2020.
//

#ifndef LAB5_TIME_H
#define LAB5_TIME_H


class Time {
private:
    int year;
    int month;
    int date;
public:
    Time();
    Time(Time const&otherTime);
    void travelToTheFuture(int year, int month, int date);
    Time getExpiringDate(int year, int month, int date);
    bool operator> (const Time &t1);
};


#endif //LAB5_TIME_H
