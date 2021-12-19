#include "Service.h"

Service::Service(string typeOfService, string date, string worker){
    Date date1(date);
    this->typeOfService = typeOfService;
    this->dateOfService = date1;
    this->worker = worker;
}

string Service::getTypeOfService() {
    return typeOfService;
}

Date& Service::getDate() {
    return dateOfService;
}


string Service::getWorker() {
    return worker;
}

void Service::setTypeOfService(string newTypeOfService){
    typeOfService = newTypeOfService;
}
void Service::setDate(string newDate){
    dateOfService = newDate;
}
void Service::setWorker(string newWorker){
    worker = newWorker;
}

void Service::print(bool completed) {
    if (completed) cout << "Service: " << typeOfService << "  " << dateOfService.getStringDate() << "  " << worker << "  completed " <<endl;
    else cout << "Service: " << typeOfService << "  " << dateOfService.getStringDate() << "  " << worker << "  not completed " <<endl;
}

