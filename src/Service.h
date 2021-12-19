#ifndef AIRLINEMANAGEMENTPROGRAM_SERVICE_H
#define AIRLINEMANAGEMENTPROGRAM_SERVICE_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Service {
    string typeOfService;
    Date dateOfService;
    string worker;
public:
    Service(string typeOfService, string date, string worker);
    string getTypeOfService();
    Date& getDate();
    string getWorker();
    void setTypeOfService(string newTypeOfService);
    void setDate(string newDate);
    void setWorker(string newWorker);
    void print(bool completed);
};


#endif //AIRLINEMANAGEMENTPROGRAM_SERVICE_H
