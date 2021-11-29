#ifndef AIRLINEMANAGEMENTPROGRAM_PLANE_H
#define AIRLINEMANAGEMENTPROGRAM_PLANE_H

#include <string>
#include <vector>
#include <queue>
#include "Flight.h"


using namespace std;

class Plane {
    string licensePlate;
    int capacity;
    vector<Flight> flightPlan;
    // queue<Service> services; //Maybe we could separate in 2 queues.
    // One with services already completed and another with services that are scheduled.
public:
    Plane(string licensePlate, int capacity);
    Plane(string licensePlate, int capacity, vector<Flight> flightPlan);
    string getLicensePlate();
    int getCapacity();
    vector<Flight> getFlightPlan();

};


#endif //AIRLINEMANAGEMENTPROGRAM_PLANE_H
