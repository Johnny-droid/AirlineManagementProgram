#ifndef AIRLINEMANAGEMENTPROGRAM_SERVICE_H
#define AIRLINEMANAGEMENTPROGRAM_SERVICE_H

#include <string>
#include <iostream>

using namespace std;

class Service {
    string typeOfService;
    string date;
    string worker;
public:
    Service(string typeOfService, string date, string worker);
    string getTypeOfService();
    string getDate();
    string getWorker();
    void setTypeOfService(string newTypeOfService);
    void setDate(string newDate);
    void setWorker(string newWorker);
    void print(bool completed);
};


#endif //AIRLINEMANAGEMENTPROGRAM_SERVICE_H
