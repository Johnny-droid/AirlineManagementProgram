#ifndef AIRLINEMANAGEMENTPROGRAM_DATE_H
#define AIRLINEMANAGEMENTPROGRAM_DATE_H

#include <string>
#include <iostream>
#include "Menu.h"

using namespace std;

class Date {
    int day;
    int month;
    int year;
public:
    Date(string date);
    bool operator==(Date date2);
    bool operator<(Date date2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_DATE_H
