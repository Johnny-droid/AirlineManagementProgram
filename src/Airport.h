#ifndef AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
#define AIRLINEMANAGEMENTPROGRAM_AIRPORT_H

#include <string>
#include <iostream>

using namespace std;

class Airport {
    int id;
    string name;
    //Binary Tree needs to be implemented
    // Transportation near the airport
public:
    Airport(int id, string name);
    int getId();
    string getName();
    void setId(int newId);
    void setName(string newName);
    void print();
};


#endif //AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
