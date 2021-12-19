#ifndef AIRLINEMANAGEMENTPROGRAM_TIME_H
#define AIRLINEMANAGEMENTPROGRAM_TIME_H

#include <string>
#include <iostream>
#include "Menu.h"

using namespace std;

class Time{
    int hour;
    int minute;
public:
    Time(string time);
    bool operator== (Time time2);
    bool operator< (Time time2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_TIME_H
