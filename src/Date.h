#ifndef AIRLINEMANAGEMENTPROGRAM_DATE_H
#define AIRLINEMANAGEMENTPROGRAM_DATE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Date {
    int day;
    int month;
    int year;
public:
    Date();
    Date(string date);
    string getStringDate() const;
    bool operator==(Date date2);
    bool operator<(Date date2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_DATE_H
