#include "Service.h"
/**
 * Creates a service object
 * @param typeOfService The service's type, could be 'management' or 'cleaning'
 * @param date The string that represents a date in the model 'DD-MM-YYYY' that will be turned into a date object
 * @param worker The name of the worker responsible for that service
 */
Service::Service(string typeOfService, string date, string worker){
    Date date1(date);
    this->typeOfService = typeOfService;
    this->dateOfService = date1;
    this->worker = worker;
}
/**
 *
 * @return The service's type
 */
string Service::getTypeOfService() {
    return typeOfService;
}
/**
 *
 * @return The service's date object
 */
Date& Service::getDate() {
    return dateOfService;
}

/**
 *
 * @return The name of the worker responsible for the service
 */
string Service::getWorker() {
    return worker;
}
/**
 * Changes the type of service to a new one.
 * @param newTypeOfService The new type of service
 */
void Service::setTypeOfService(string newTypeOfService){
    typeOfService = newTypeOfService;
}/**
 * Changes the date of the service to a new one
 * @param newDate The string that represents the new date in the model 'DD-MM-YYYY' that will be turned into a date object
 */
void Service::setDate(string newDate){
    Date d(newDate);
    dateOfService = d;
}
/**
 * Changes the name of the worker responsible for the service
 * @param newWorker The name of the new worker
 */
void Service::setWorker(string newWorker){
    worker = newWorker;
}
/**
 * Prints an indication of whether or not the service has been completed
 * @param completed True, if the service has already been completed. False if otherwise.
 */
void Service::print(bool completed) {
    if (completed) cout << "Service: " << typeOfService << "  " << dateOfService.getStringDate() << "  " << worker << "  completed " <<endl;
    else cout << "Service: " << typeOfService << "  " << dateOfService.getStringDate() << "  " << worker << "  not completed " <<endl;
}

