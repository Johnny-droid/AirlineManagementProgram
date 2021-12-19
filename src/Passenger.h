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
    int getId() const;
    string getName() const;
    int getAge() const;
    void setId(int newId);
    void setName(string newName);
    void setAge(int newAge);
    void print();

    static bool compareById(const Passenger& passenger1, const Passenger& passenger2);
    static bool compareByName(const Passenger& passenger1, const Passenger& passenger2);
    static bool compareByAge(const Passenger& passenger1, const Passenger& passenger2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_PASSENGER_H
