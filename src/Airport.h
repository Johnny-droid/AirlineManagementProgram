#ifndef AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
#define AIRLINEMANAGEMENTPROGRAM_AIRPORT_H

#include <string>

using namespace std;

class Airport {
    string name;
    //Binary Tree needs to be implemented
public:
    Airport(string name) {this->name = name;}

    string getName();
};


#endif //AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
