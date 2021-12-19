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
    bool operator== (const Time& time2);
    bool operator< (const Time& time2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_TIME_H
