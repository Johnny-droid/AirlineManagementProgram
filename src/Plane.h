#ifndef AIRLINEMANAGEMENTPROGRAM_PLANE_H
#define AIRLINEMANAGEMENTPROGRAM_PLANE_H

#include <string>
#include <vector>
#include <queue>
#include "Flight.h"
#include "Service.h"

using namespace std;

class Plane {
    string licensePlate;
    int capacity;
    vector<Flight> flightPlan;
    queue<Service> servicesToBeDone;
    queue<Service> servicesCompleted;
public:
    Plane(string licensePlate, int capacity);
    Plane(string licensePlate, int capacity, vector<Flight> flightPlan);
    string getLicensePlate();
    int getCapacity();
    vector<Flight> getFlightPlan();
    queue<Service> getServicesToBeDone();
    queue<Service> getServicesCompleted();
};


#endif //AIRLINEMANAGEMENTPROGRAM_PLANE_H
