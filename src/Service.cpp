#include "Service.h"

Service::Service(string typeOfService, string date, string worker){
    this->typeOfService = typeOfService;
    this->date = date;
    this->worker = worker;
}

string Service::getTypeOfService() {
    return typeOfService;
}

string Service::getDate() {
    return date;
}

string Service::getWorker() {
    return worker;
}

void Service::setTypeOfService(string newTypeOfService){
    typeOfService = newTypeOfService;
}
void Service::setDate(string newDate){
    date = newDate;
}
void Service::setWorker(string newWorker){
    worker = newWorker;
}

void Service::print(bool completed) {
    if (completed) cout << "Service: " << typeOfService << "  " << date << "  " << worker << "  completed " <<endl;
    else cout << "Service: " << typeOfService << "  " << date << "  " << worker << "  not completed " <<endl;
}

