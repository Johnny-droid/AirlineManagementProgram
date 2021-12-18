#ifndef AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
#define AIRLINEMANAGEMENTPROGRAM_AIRPORT_H

#include <string>
#include <iostream>
#include "bst.h"
#include "LocalTransport.h"

using namespace std;

class Airport {
    int id;
    string name;
    BST<LocalTransport> bst;
public:
    Airport(int id, string name);
    int getId();
    string getName();
    void setId(int newId);
    void setName(string newName);
    void print();
};


#endif //AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
