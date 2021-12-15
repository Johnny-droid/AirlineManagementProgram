#ifndef AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
#define AIRLINEMANAGEMENTPROGRAM_AIRPORT_H

#include <string>

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
};


#endif //AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
