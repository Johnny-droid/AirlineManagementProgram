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

void Service::print() {
    cout << "Service: " << typeOfService << "  " << date << "  " << worker << endl;
}

