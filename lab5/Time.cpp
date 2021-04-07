//
// Created by Александр on 30.11.2020.
//

#include "Time.h"


Time::Time() {
    this->date = 1;
    this->month = 1;
    this->year = 2020;
}

Time::Time(Time const&otherTime) {
    this->date = otherTime.date;
    this->month = otherTime.month;
    this->year = otherTime.year;
}

void Time::travelToTheFuture(int year, int month, int date) {
    this->date += date;
    if (this->date > 30) {
        this->date -= 30;
        this->month += 1;
    }
    this->month += month;
    if (this->month > 12) {
        this->month -= 12;
        this->year += 1;
    }
    this->year += year;
}

bool Time::operator>(const Time &t1) {
    if (this->year > t1.year) {
        return true;
    }
    if (this->year < t1.year) {
        return false;
    }
    if (this->month > t1.month) {
        return true;
    }
    if (this->month < t1.month) {
        return false;
    }
    if (this->date > t1.date) {
        return true;
    }
    if (this->date < t1.date) {
        return false;
    }
    return false;
}

Time Time::getExpiringDate(int year, int month, int date) {
    this->travelToTheFuture(year, month, date);
    return *this;
}