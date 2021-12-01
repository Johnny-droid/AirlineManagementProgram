#ifndef AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
#define AIRLINEMANAGEMENTPROGRAM_PASSENGER_H

#include <string>

using namespace std;

class Passenger {
    int id;
    string name;
    int age;
public:
    Passenger(int id, string name, int age);
    string getName() {return name;};
    int getAge() {return age;};
};


#endif //AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
