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

void Plane::printFlights() {
    for (Flight flight: flightPlan) {
        cout << "Flight: " << flight.getNumber() << "      Duration: " << flight.getDuration() << endl;
        cout << "Airport    Origin: " << flight.getOrigin()->getName() << "      Destiny:  " << flight.getDestiny()->getName() << endl;
    }

}

void Plane::printServices() {
    cout << "Services not yet completed" << endl;
    while (!servicesToBeDone.empty()) {
        Service service = servicesToBeDone.front();
        service.print();
        servicesToBeDone.pop();
    }
    cout << endl;
    cout << "Services completed" << endl;
    while (!servicesCompleted.empty()) {
        Service service = servicesCompleted.front();
        service.print();
        servicesCompleted.pop();
    }
}
