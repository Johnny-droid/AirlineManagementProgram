#include "Plane.h"

Plane::Plane(string licensePlate, int capacity) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    this->flightPlan = vector<Flight>();
    this->servicesCompleted = queue<Service>();
    this->servicesToBeDone = queue<Service>();
}

Plane::Plane(string licensePlate, int capacity, vector<Flight> flightPlan, queue<Service> servicesCompleted, queue<Service> servicesToBeDone) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
    this->servicesCompleted = servicesCompleted;
    this->servicesToBeDone = servicesToBeDone;
}

string Plane::getLicensePlate() const {
    return licensePlate;
}
/**
 * ele vai buscar o int
 * @return retorna capacidade
 */
int Plane::getCapacity() const {
    return capacity;
}
/**
 * ele vai buscar o flight plan
 * @return
 */
vector<Flight>& Plane::getFlightPlan() {
    return flightPlan;
}
/**
 *
 * @return retorna o serices to be done
 */
queue<Service>& Plane::getServicesToBeDone() {
    return servicesToBeDone;
}

queue<Service>& Plane::getServicesCompleted() {
    return servicesCompleted;
}
void Plane::setLicensePlate(string newLicensePlate){
    licensePlate = newLicensePlate;
}
void Plane::setCapacity(int newCapacity){
    capacity = newCapacity;
}

void Plane::printFlights() {
    for (Flight flight: flightPlan) {
        flight.print();
    }

}

void Plane::print() {
    cout << "Plane   License Plate: " << licensePlate << "    Capacity: " << capacity << endl;
}

void Plane::printServices() {
    queue<Service> copyServicesToBeDone = servicesToBeDone;
    queue<Service> copyServicesCompleted = servicesCompleted;

    while (!copyServicesToBeDone.empty()) {
        Service service = copyServicesToBeDone.front();
        service.print(false);
        copyServicesToBeDone.pop();
    }


    while (!copyServicesCompleted.empty()) {
        Service service = copyServicesCompleted.front();
        service.print(true);
        copyServicesCompleted.pop();
    }
}

void Plane::printServicesCompleted() {
    queue<Service> copyServicesCompleted = servicesCompleted;
    cout << "Services completed" << endl;
    while (!copyServicesCompleted.empty()) {
        Service service = copyServicesCompleted.front();
        service.print(true);
        copyServicesCompleted.pop();
    }
};

void Plane::printServicesToBeDone() {
    queue<Service> copyServicesToBeDone = servicesToBeDone;
    cout << "Services not yet completed" << endl;
    while (!copyServicesToBeDone.empty()) {
        Service service = copyServicesToBeDone.front();
        service.print(false);
        copyServicesToBeDone.pop();
    }
};

void Plane::completeLastService() {
    Service serviceDone = servicesToBeDone.front();
    serviceDone.print(true);
    cout << "This service was completed" << endl;
    servicesToBeDone.pop();
    servicesCompleted.push(serviceDone);
};


bool Plane::compareByLicensePlate(const Plane& plane1, const Plane& plane2) {
    return plane1.getLicensePlate() < plane2.getLicensePlate();
}

bool Plane::compareByCapacity(const Plane& plane1, const Plane& plane2) {
    return plane1.getCapacity() < plane2.getCapacity();
}

bool Plane::compareByNumberFlights(Plane& plane1, Plane& plane2) {
    return plane1.getFlightPlan().size() < plane2.getFlightPlan().size();
}







