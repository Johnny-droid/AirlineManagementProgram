#ifndef AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
#define AIRLINEMANAGEMENTPROGRAM_PASSENGER_H

#include <string>

using namespace std;

class Passenger {
    int id;
    string name;
    int age;
public:
    Passenger(string fileString);
    Passenger(int id, string name, int age);
    int getId();
    string getName();
    int getAge();
};


#endif //AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
