#ifndef AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
#define AIRLINEMANAGEMENTPROGRAM_PASSENGER_H

#include <string>
#include <iostream>

using namespace std;

class Passenger {
    int id;
    string name;
    int age;
public:
    Passenger(int id, string name, int age);
    int getId();
    string getName();
    int getAge();
    void setId(int newId);
    void setName(string newName);
    void setAge(int newAge);
    void print();
};


#endif //AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
