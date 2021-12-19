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
    Plane(string licensePlate, int capacity);
    Plane(string licensePlate, int capacity, vector<Flight> flightPlan, queue<Service> servicesCompleted, queue<Service> servicesToBeDone);
    string getLicensePlate() const;
    int getCapacity() const;
    vector<Flight> &getFlightPlan();
    queue<Service> &getServicesToBeDone();
    queue<Service> &getServicesCompleted();
    void setLicensePlate(string newLicensePlate);
    void setCapacity(int newCapacity);
    void print();
    void printFlights();
    void printServices();
    void printServicesCompleted();
    void printServicesToBeDone();
    void completeLastService();

    static bool compareByLicensePlate(const Plane& plane1, const Plane& plane2);
    static bool compareByCapacity(const Plane& plane1, const Plane& plane2);
};


#endif //AIRLINEMANAGEMENTPROGRAM_PLANE_H
