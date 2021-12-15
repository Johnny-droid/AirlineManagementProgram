#include "Plane.h"

Plane::Plane(string licensePlate, int capacity, vector<Flight> flightPlan, queue<Service> services) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
    this->servicesToBeDone = services;
    queue<Service> emptyQ;
    this->servicesCompleted = emptyQ;
}

string Plane::getLicensePlate() {
    return licensePlate;
}

int Plane::getCapacity() {
    return capacity;
}

vector<Flight> Plane::getFlightPlan() {
    return flightPlan;
}

queue<Service> Plane::getServicesToBeDone() {
    return servicesToBeDone;
}

queue<Service> Plane::getServicesCompleted() {
    return servicesCompleted;
}
