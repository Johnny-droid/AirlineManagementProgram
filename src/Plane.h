#ifndef AIRLINEMANAGEMENTPROGRAM_PLANE_H
#define AIRLINEMANAGEMENTPROGRAM_PLANE_H

#include <string>
#include <vector>
#include <iostream>
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
    Plane(string licensePlate, int capacity, vector<Flight> flightPlan, queue<Service> services);
    string getLicensePlate();
    int getCapacity();
    vector<Flight> getFlightPlan();
    queue<Service> getServicesToBeDone();
    queue<Service> getServicesCompleted();
    void printFlights();
    void printServices();
};


#endif //AIRLINEMANAGEMENTPROGRAM_PLANE_H
