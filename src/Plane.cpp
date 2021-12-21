#include "Plane.h"

/**
 * Create a plane object with an empty vector for flight plans and empty queues for services completed and services to be done
 * @param licensePlate The plane's license plate
 * @param capacity The maximum amount of passengers that a plane can carry in a flight
 */
Plane::Plane(string licensePlate, int capacity) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    this->flightPlan = vector<Flight>();
    this->servicesCompleted = queue<Service>();
    this->servicesToBeDone = queue<Service>();
}
/**
 * Create a plane object
 * @param licensePlate The plane's license plate
 * @param capacity The maximum amount of passengers that a plane can carry in a flight
 * @param flightPlan Vector with the all Flight objects that belong to the plane
 * @param servicesCompleted Queue with all the services with all the services that have been made to the plane
 * @param servicesToBeDone Queue with all the services planned, but not done yet, to the plane
 */
Plane::Plane(string licensePlate, int capacity, vector<Flight> flightPlan, queue<Service> servicesCompleted, queue<Service> servicesToBeDone) {
    this->licensePlate = licensePlate;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
    this->servicesCompleted = servicesCompleted;
    this->servicesToBeDone = servicesToBeDone;
}
/**
 *
 * @return The plane's license plate
 */
string Plane::getLicensePlate() const {
    return licensePlate;
}
/**
 *
 * @return The plane's capacity
 */
int Plane::getCapacity() const {
    return capacity;
}
/**
 *
 * @return The plane's flight plan
 */
vector<Flight>& Plane::getFlightPlan() {
    return flightPlan;
}
/**
 *
 * @return The services that have not been done yet
 */
queue<Service>& Plane::getServicesToBeDone() {
    return servicesToBeDone;
}
/**
 *
 * @return The services that have already been done
 */
queue<Service>& Plane::getServicesCompleted() {
    return servicesCompleted;
}
/**
 * Changes the license plate to a new one
 * @param newLicensePlate The new license plate
 */
void Plane::setLicensePlate(string newLicensePlate){
    licensePlate = newLicensePlate;
}
/**
 * Changes the capacity to a new one
 * @param newCapacity The new capacity
 */
void Plane::setCapacity(int newCapacity){
    capacity = newCapacity;
}
/**
 * Prints every flight on the the plane's flight plan
 */
void Plane::printFlights() {
    for (Flight flight: flightPlan) {
        flight.print();
    }

}
/**
 * Print that represents the plane object by showing its license plate and capacity
 */
void Plane::print() {
    cout << "Plane   License Plate: " << licensePlate << "    Capacity: " << capacity << endl;
}
/**
 * Prints all of the plane's services, completed or not
 */
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
/**
 * Prints the plane's services that have been completed
 */
void Plane::printServicesCompleted() {
    queue<Service> copyServicesCompleted = servicesCompleted;
    cout << "Services completed" << endl;
    while (!copyServicesCompleted.empty()) {
        Service service = copyServicesCompleted.front();
        service.print(true);
        copyServicesCompleted.pop();
    }
};
/**
 * Prints the plane's services that have not been done yet
 */
void Plane::printServicesToBeDone() {
    queue<Service> copyServicesToBeDone = servicesToBeDone;
    cout << "Services not yet completed" << endl;
    while (!copyServicesToBeDone.empty()) {
        Service service = copyServicesToBeDone.front();
        service.print(false);
        copyServicesToBeDone.pop();
    }
};
/**
 * When the first service from the to be done queue is completed, takes it out of the queue and puts it in the end of the queue of completed services
 */
void Plane::completeLastService() {
    Service serviceDone = servicesToBeDone.front();
    serviceDone.print(true);
    cout << "This service was completed" << endl;
    servicesToBeDone.pop();
    servicesCompleted.push(serviceDone);
};

/**
 * Compares two planes by their license plate
 * @param plane1 The first plane
 * @param plane2 The second plane
 * @return True, if the first plane's license plate is alphabetically before the second plane's. False, if otherwhise.
 */
bool Plane::compareByLicensePlate(const Plane& plane1, const Plane& plane2) {
    return plane1.getLicensePlate() < plane2.getLicensePlate();
}
/**
 * Compares two planes by their capacity
 * @param plane1 The first plane
 * @param plane2 The second plane
 * @return True, if the first plane's capacity is smaller than the second plane's. False, if otherwise.
 */
bool Plane::compareByCapacity(const Plane& plane1, const Plane& plane2) {
    return plane1.getCapacity() < plane2.getCapacity();
}
/**
 * Compares two planes by their number of flights
 * @param plane1 The first plane
 * @param plane2 The second plane
 * @return True, if the first plane's flight plan size is smaller than the second plane's. False, if otherwise.
 */
bool Plane::compareByNumberFlights(Plane& plane1, Plane& plane2) {
    return plane1.getFlightPlan().size() < plane2.getFlightPlan().size();
}







