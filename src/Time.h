#ifndef AIRLINEMANAGEMENTPROGRAM_TIME_H
#define AIRLINEMANAGEMENTPROGRAM_TIME_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Time{
    int hour;
    int minute;
public:
    Time(string time);
    int getHour() const;
    int getMinute() const;
    string getStringTime() const;
    bool operator== (const Time& time2);
    bool operator< (const Time& time2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_TIME_H
