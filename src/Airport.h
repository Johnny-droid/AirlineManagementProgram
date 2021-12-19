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
    BST<LocalTransport> bst = BST<LocalTransport>(LocalTransport());
public:
    Airport(int id, string name);
    Airport(int id, string name, BST<LocalTransport> bst);
    int getId() const;
    string getName() const;
    BST<LocalTransport>& getBST();
    int getBSTSize() const;
    void setId(int newId);
    void setName(string newName);
    void print();
    void printLocalTransports();
    bool isLocalTransportId(int id);

    static bool compareById(const Airport& airport1, const Airport& airport2);
    static bool compareByName(const Airport& airport1, const Airport& airport2);
    static bool compareByNumberLocalTransports(const Airport& airport1, const Airport& airport2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_AIRPORT_H
