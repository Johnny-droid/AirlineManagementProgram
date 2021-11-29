#include "Plane.h"


Plane::Plane(string licensePlate, int capacity) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    vector<Flight> empty;
    this->flightPlan = empty;
}

Plane::Plane(string licensePlate, int capacity, vector<Flight> flightPlan) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
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
